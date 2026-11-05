"""Converte os .md desta pasta em .docx (pandoc) e dá altura aos quadros de registro.

Lab02 (displays de 7 segmentos). Copiado do build_docx.py do lab01
(aula_2026-10-15), com uma diferença: estes documentos citam os esquemas
como LINK relativo (../../imagens/<arquivo>.png). O filtro esquemas_no_docx.lua
embute cada esquema no passo "Confira com o esquema" e troca o link pelo
endereço no GitHub; o pandoc roda com a pasta dos .md como diretório de
trabalho e --resource-path, para achar os .png e embuti-los no .docx.

Uso (a partir desta pasta):  python build_docx.py
Saída: docx/doc1_*.docx, docx/doc2_*.docx, docx/doc3_*.docx
Suba os .docx ao Google Drive e abra como Google Docs.
"""
import argparse
import subprocess
from pathlib import Path

from docx import Document
from docx.oxml import OxmlElement
from docx.oxml.ns import qn
from docx.shared import Cm

__version__ = "1.1"

AQUI = Path(__file__).resolve().parent
SAIDA = AQUI / "docx"
FILTRO = AQUI / "esquemas_no_docx.lua"
ALTURA_CM = 3.5  # altura da linha vazia dos quadros de registro


def bordas(tabela):
    """Contorno e grade em todas as células (o pandoc gera tabelas sem bordas)."""
    tblPr = tabela._tbl.tblPr
    antigo = tblPr.find(qn("w:tblBorders"))
    if antigo is not None:
        tblPr.remove(antigo)
    b = OxmlElement("w:tblBorders")
    for lado in ("top", "left", "bottom", "right", "insideH", "insideV"):
        e = OxmlElement(f"w:{lado}")
        e.set(qn("w:val"), "single")
        e.set(qn("w:sz"), "6")
        e.set(qn("w:color"), "808080")
        b.append(e)
    tblPr.append(b)


LARGURA_CM = 16.0          # largura útil da página (A4/Letter com margens do pandoc)
COR_CABECALHO = "DCE6F1"   # fundo da linha de título das tabelas
COR_CAIXA = "EEF3F8"       # fundo dos quadros de orientação (citações)
COR_PREPARACAO = "FFF2CC"  # faixa "PREPARAÇÃO"
COR_ATIVIDADE = "D9EAD3"   # faixa "ATIVIDADE"


def _sombra(pr, cor):
    antigo = pr.find(qn("w:shd"))
    if antigo is not None:
        pr.remove(antigo)
    s = OxmlElement("w:shd")
    s.set(qn("w:val"), "clear")
    s.set(qn("w:color"), "auto")
    s.set(qn("w:fill"), cor)
    pr.append(s)


def formatar_tabela(tabela):
    """Para o Google Docs: borda explícita em CADA célula (o Docs perdia a linha
    entre o título e a 1ª linha), título em negrito com fundo, largura total da
    página e colunas proporcionais ao texto (selos e rótulos ficam estreitos)."""
    linhas = tabela.rows
    ncol = len(tabela.columns)
    pesos = []
    for c in range(ncol):
        maior = max((len(l.cells[c].text.strip()) for l in linhas), default=0)
        pesos.append(min(max(maior, 8), 48))
    total = sum(pesos)
    larg = [Cm(LARGURA_CM * w / total) for w in pesos]

    tblPr = tabela._tbl.tblPr
    for tag in ("w:tblW", "w:tblLayout"):
        e = tblPr.find(qn(tag))
        if e is not None:
            tblPr.remove(e)
    w = OxmlElement("w:tblW"); w.set(qn("w:type"), "dxa"); w.set(qn("w:w"), str(int(LARGURA_CM / 2.54 * 1440)))
    tblPr.append(w)
    lay = OxmlElement("w:tblLayout"); lay.set(qn("w:type"), "fixed")
    tblPr.append(lay)
    grade = tabela._tbl.find(qn("w:tblGrid"))
    if grade is not None:
        for gc, lw in zip(grade.findall(qn("w:gridCol")), larg):
            gc.set(qn("w:w"), str(int(lw.cm / 2.54 * 1440)))

    for i, linha in enumerate(linhas):
        for c, cel in enumerate(linha.cells):
            cel.width = larg[c]
            tcPr = cel._tc.get_or_add_tcPr()
            antigo = tcPr.find(qn("w:tcBorders"))
            if antigo is not None:
                tcPr.remove(antigo)
            b = OxmlElement("w:tcBorders")
            for lado in ("top", "left", "bottom", "right"):
                e = OxmlElement(f"w:{lado}")
                e.set(qn("w:val"), "single"); e.set(qn("w:sz"), "6"); e.set(qn("w:color"), "808080")
                b.append(e)
            tcPr.append(b)
            if i == 0 and not e_quadro_de_registro(tabela):
                _sombra(tcPr, COR_CABECALHO)
                for par in cel.paragraphs:
                    for run in par.runs:
                        run.bold = True


def destacar_caixas(doc):
    """Citações (orientação, selos, avisos) viram caixa com fundo e barra azul à
    esquerda; as faixas PREPARAÇÃO e ATIVIDADE ganham cor própria."""
    for par in doc.paragraphs:
        pPr = par._p.get_or_add_pPr()
        texto = par.text.strip()
        if par.style.name in ("Block Text", "Quote"):
            _sombra(pPr, COR_CAIXA)
            bd = OxmlElement("w:pBdr")
            e = OxmlElement("w:left")
            e.set(qn("w:val"), "single"); e.set(qn("w:sz"), "24"); e.set(qn("w:space"), "6"); e.set(qn("w:color"), "2E75B6")
            bd.append(e)
            pPr.append(bd)
        elif texto.startswith("🧰"):
            _sombra(pPr, COR_PREPARACAO)
        elif texto.startswith("🚀"):
            _sombra(pPr, COR_ATIVIDADE)



def e_quadro_de_registro(tabela):
    """Quadro = tabela de 1 coluna e 2 linhas, com a 2ª linha vazia."""
    return (
        len(tabela.columns) == 1
        and len(tabela.rows) == 2
        and not tabela.rows[1].cells[0].text.strip()
    )


def converter(md):
    SAIDA.mkdir(exist_ok=True)
    saida = SAIDA / (md.stem + ".docx")
    # cwd e --resource-path na pasta do .md: ../../imagens/*.png é achado e embutido.
    subprocess.run(
        [
            "pandoc", md.name,
            # o "> 1." logo abaixo do título do quadro 🔎 vira lista (e não um parágrafo só)
            "-f", "markdown+lists_without_preceding_blankline",
            "--lua-filter", str(FILTRO),
            "--resource-path", str(md.parent),
            "-o", str(saida),
        ],
        check=True,
        cwd=md.parent,
    )
    doc = Document(saida)
    n = 0
    for t in doc.tables:
        bordas(t)
        formatar_tabela(t)
        if e_quadro_de_registro(t):
            t.rows[1].height = Cm(ALTURA_CM)
            n += 1
    destacar_caixas(doc)
    doc.save(saida)
    print(f"{saida.name}: {len(doc.tables)} tabelas, {n} quadros de registro")

def main():
    ap = argparse.ArgumentParser(
        description=__doc__.split("\n\n")[0],
        epilog="Uso, saída e requisitos: veja o docstring no início deste arquivo.",
    )
    ap.add_argument("-V", "--version", action="version", version=f"%(prog)s {__version__}")
    ap.parse_args()
    for md in sorted(AQUI.glob("doc[0-9]_*.md")):
        converter(md)


if __name__ == "__main__":
    main()
