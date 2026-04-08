import os
import re
from pathlib import Path
from dotenv import load_dotenv

from langchain_community.document_loaders import PyPDFLoader, TextLoader
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_huggingface import HuggingFaceEmbeddings
from langchain_chroma import Chroma
from langchain_core.documents import Document

load_dotenv()

BASE_DIR = Path(__file__).parent.parent
CORPUS_DIR = BASE_DIR / "corpus"
VECTOR_DIR = str(BASE_DIR / "vectorstore")

EMBED_MODEL = os.getenv("EMBED_MODEL", "sentence-transformers/all-MiniLM-L6-v2")

def split_verilog_by_module(text: str, source: str) -> list[dict]:
    chunks = []
    parts = re.split(r'(?=\bmodule\b)', text)
    for part in parts:
        cleaned = part.strip()
        if len(cleaned.split()) > 50:
            chunks.append({"content": cleaned, "source": source})
    return chunks

def load_spec(spec_dir: Path) -> list[Document]:
    docs: list[Document] = []
    for pdf_file in spec_dir.glob("*.pdf"):
        print(f"Loading spec: {pdf_file.name}")
        loader = PyPDFLoader(str(pdf_file))
        pages = loader.load()

        splitter = RecursiveCharacterTextSplitter(
            chunk_size=1500,
            chunk_overlap=200,
            separators=["\n\n", "\n", " "]
        )
        docs.extend(splitter.split_documents(pages))
    return docs

def load_rtl(rtl_dir: Path) -> list[Document]:
    docs: list[Document] = []
    for v_file in rtl_dir.glob("*.v"):
        print(f'Loading RTL: {v_file.name}')
        text = v_file.read_text(encoding="utf-8", errors="ignore")
        chunks = split_verilog_by_module(text, str(v_file))
        for chunk in chunks:
            docs.append(Document(
                page_content=chunk["content"],
                metadata={"source": chunk["source"], "type": "rtl_reference"}
            ))
    return docs

def load_patterns(pattern_dir: Path) -> list[Document]:
    docs: list[Document] = []
    for md_file in pattern_dir.glob("*.md"):
        print(f"Loading pattern: {md_file.name}")
        loader = TextLoader(str(md_file), encoding="utf-8")
        raw = loader.load()

        splitter = RecursiveCharacterTextSplitter(
            chunk_size=800,
            chunk_overlap=100,
        )
        docs.extend(splitter.split_documents(raw))
    return docs

def ingest():
    all_docs = []

    print("Loading RISC-V spec...")
    all_docs.extend(load_spec(CORPUS_DIR / "spec"))

    print("Loading RTL refrence...")
    all_docs.extend(load_rtl(CORPUS_DIR / "rtl_ref"))

    print("Loading Verilog patterns & bug references...")
    all_docs.extend(load_patterns(CORPUS_DIR / "patterns"))

    print(f"\nTotal chunks to embed: {len(all_docs)}")

    
    embeddings = HuggingFaceEmbeddings(
        model_name=EMBED_MODEL,
        model_kwargs={"device": "cpu"}
    )

    print("Building ChromaDB vector store...")
    vectorstore = Chroma.from_documents(
        documents=all_docs,
        embedding=embeddings,
        persist_directory=VECTOR_DIR
    )

    print(f"\n{len(all_docs)} chunks stored in {VECTOR_DIR}")
    return vectorstore

if __name__ == "__main__":
    ingest()
