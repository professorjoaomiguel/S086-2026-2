"""Converte os .md desta pasta em .pdf (pandoc -> HTML -> Chrome headless).

Mesma entrada do build_docx.py (os doc*.md), saída em pdf/. O estilo está em
pdf.css (tabelas com largura pelo conteúdo, quadros de registro com altura,
dicas em caixa verde). Se existir esquemas_no_docx.lua nesta pasta, o mesmo
filtro embute os esquemas citados como link relativo.

Uso (a partir desta pasta):  python build_pdf.py
Saída: pdf/doc1_*.pdf, pdf/doc2_*.pdf, pdf/doc3_*.pdf
Requer: pandoc e Google Chrome (ou Microsoft Edge) instalados.
"""
import argparse
import shutil
import subprocess
import tempfile
from pathlib import Path

__version__ = "1.0"

AQUI = Path(__file__).resolve().parent
SAIDA = AQUI / "pdf"
CSS = AQUI / "pdf.css"
FILTRO = AQUI / "esquemas_no_docx.lua"
NAVEGADORES = [
    r"C:\Program Files\Google\Chrome\Application\chrome.exe",
    r"C:\Program Files (x86)\Google\Chrome\Application\chrome.exe",
    r"C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe",
]


def achar_navegador():
    for caminho in NAVEGADORES:
        if Path(caminho).exists():
            return caminho
    achado = shutil.which("chrome") or shutil.which("msedge")
    if achado:
        return achado
    raise SystemExit("Chrome ou Edge não encontrado: ajuste NAVEGADORES.")


def converter(md, navegador, tmp):
    html = tmp / (md.stem + ".html")
    saida = SAIDA / (md.stem + ".pdf")
    comando = [
        "pandoc", md.name,
        "-f", "markdown+lists_without_preceding_blankline",
        "--resource-path", str(md.parent),
        "--embed-resources", "--standalone",
        "-c", str(CSS),
        "--metadata", f"pagetitle={md.stem}",
        "-o", str(html),
    ]
    if FILTRO.exists():
        comando[1:1] = ["--lua-filter", str(FILTRO)]
    # cwd na pasta do .md: ../../imagens/*.png é achado e embutido.
    subprocess.run(comando, check=True, cwd=md.parent)
    SAIDA.mkdir(exist_ok=True)
    subprocess.run(
        [
            navegador, "--headless", "--disable-gpu", "--no-pdf-header-footer",
            f"--print-to-pdf={saida}", html.as_uri(),
        ],
        check=True,
        capture_output=True,
    )
    print(f"{saida.name}")

def main():
    ap = argparse.ArgumentParser(
        description=__doc__.split("\n\n")[0],
        epilog="Uso, saída e requisitos: veja o docstring no início deste arquivo.",
    )
    ap.add_argument("-V", "--version", action="version", version=f"%(prog)s {__version__}")
    ap.parse_args()
    navegador = achar_navegador()
    with tempfile.TemporaryDirectory() as t:
        for md in sorted(AQUI.glob("doc[0-9]_*.md")):
            converter(md, navegador, Path(t))


if __name__ == "__main__":
    main()
