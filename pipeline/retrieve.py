import os
from pathlib import Path
from dotenv import load_dotenv
from langchain_chroma import Chroma
from langchain_huggingface import HuggingFaceEmbeddings

load_dotenv()

BASE_DIR = Path(__file__).parent.parent
VECTOR_DIR = str(BASE_DIR / "vectorstore")
EMBED_MODEL = "sentence-transformers/all-MiniLM-L6-v2"

def load_vectorstore():
    embeddings = HuggingFaceEmbeddings(
        model_name=EMBED_MODEL,
        model_kwargs={"device": "cpu"}
    )
    return Chroma(
        persist_directory=VECTOR_DIR,
        embedding_function=embeddings,
    )

def retrieve(query: str, k: int = 8) -> list:
    vs = load_vectorstore()
    results = vs.similarity_search_with_score(query, k=k)
    return results

def format_context(results: list) -> str:
    context_parts = []
    for i, (doc, score) in enumerate(results):
        source = doc.metadata.get("source", "unknown")
        source_name = Path(source).name if source != "unknown" else "unknown"
        context_parts.append(
            f"--- Chunk {i+1} (source: {source_name}, score: {score:.3f}) ---\n"
            f"{doc.page_content}\n"
        )
    return "\n".join(context_parts)

if __name__ == "__main__":
    query = "RISC-V register file with 32 registers x0 hardwired to zero"
    print(f"Query: {query}\n")
    results = retrieve(query, k=4)
    print(format_context(results))
