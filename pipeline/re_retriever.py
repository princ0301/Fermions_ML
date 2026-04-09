import os
from pathlib import Path
from dotenv import load_dotenv
from langchain_chroma import Chroma
from langchain_huggingface import HuggingFaceEmbeddings
from sentence_transformers import CrossEncoder

load_dotenv()

BASE_DIR     = Path(__file__).parent.parent
VECTOR_DIR   = str(BASE_DIR / "vectorstore")
EMBED_MODEL  = "sentence-transformers/all-MiniLM-L6-v2"
RERANK_MODEL = "cross-encoder/ms-marco-MiniLM-L-6-v2"

print("Loading reranker model...")
reranker = CrossEncoder(RERANK_MODEL)

# Keywords that indicate chunks irrelevant to RV32I base ISA
RV32I_BLACKLIST = [
    "RVC", "RV64", "RV128", "compressed instruction",
    "quadword", "floating-point extension", "C.ADDI", "FLDSP"
]

def is_relevant(text: str) -> bool:
    """Filter out chunks dominated by non-RV32I content."""
    blacklist_hits = sum(1 for kw in RV32I_BLACKLIST if kw in text)
    return blacklist_hits < 2

def load_vectorstore():
    embeddings = HuggingFaceEmbeddings(
        model_name=EMBED_MODEL,
        model_kwargs={"device": "cpu"}
    )
    return Chroma(
        persist_directory=VECTOR_DIR,
        embedding_function=embeddings
    )

def retrieve(query: str, k: int = 8, fetch_k: int = 30) -> list:
    """
    Retrieve top-k chunks using embedding similarity + cross-encoder re-ranking.

    Pipeline:
    1. Fetch fetch_k=30 candidates via embedding similarity
    2. Filter irrelevant chunks (RVC, RV64, etc.)
    3. Deduplicate by content hash
    4. Re-rank using cross-encoder
    5. Return top-k
    """
    vs = load_vectorstore()

    # Step 1: Broad retrieval
    print(f"  [Retrieval] Fetching top-{fetch_k} candidates...")
    candidates = vs.similarity_search_with_score(query, k=fetch_k)
    print(f"  [Filter] Before filter: {len(candidates)} chunks")

    # Step 2: Filter irrelevant chunks
    candidates = [(doc, score) for doc, score in candidates
                  if is_relevant(doc.page_content)]
    print(f"  [Filter] After filter: {len(candidates)} chunks")

    # Step 3: Deduplicate by content hash
    seen = set()
    deduped = []
    for doc, score in candidates:
        content_hash = hash(doc.page_content[:200])
        if content_hash not in seen:
            seen.add(content_hash)
            deduped.append((doc, score))
    print(f"  [Dedup] After dedup: {len(deduped)} chunks")

    # Step 4: Re-rank using cross-encoder
    print(f"  [Reranker] Scoring {len(deduped)} candidates...")
    pairs = [(query, doc.page_content) for doc, _ in deduped]
    rerank_scores = reranker.predict(pairs)

    # Step 5: Sort by reranker score
    ranked = sorted(
        zip(rerank_scores, [doc for doc, _ in deduped]),
        key=lambda x: x[0],
        reverse=True
    )

    top_k = [(doc, score) for score, doc in ranked[:k]]

    print(f"  [Reranker] Top-{k} selected. Score range: "
          f"{ranked[0][0]:.3f} → {ranked[min(k-1, len(ranked)-1)][0]:.3f}")

    return top_k

def format_context(results: list) -> str:
    context_parts = []
    for i, (doc, score) in enumerate(results):
        source = doc.metadata.get("source", "unknown")
        source_name = Path(source).name if source != "unknown" else "unknown"
        context_parts.append(
            f"--- Chunk {i+1} (source: {source_name}, rerank_score: {score:.3f}) ---\n"
            f"{doc.page_content}\n"
        )
    return "\n".join(context_parts)

if __name__ == "__main__":
    query = "RISC-V RV32I opcode encoding table funct3 funct7 instruction format"
    print(f"Query: {query}\n")
    results = retrieve(query, k=8, fetch_k=30)
    print("\n" + format_context(results))