-- Filtro pandoc usado por build_docx.py (lab02).
--
-- Os .md citam os esquemas como LINK: [texto](../../imagens/<arquivo>.png).
-- No .docx (Google Docs) esse caminho relativo não abre. Este filtro:
--   1) troca o destino de cada link ../../imagens/*.png pelo endereço do arquivo
--      no GitHub (o link continua clicável no Google Docs);
--   2) embute a imagem logo DEPOIS do bloco de nível superior em que ela é
--      citada pela ÚLTIMA vez (o passo "Confira com o esquema ... depois de
--      montar"), e não nas Referências do começo do documento.

local BASE = "https://github.com/professorjoaomiguel/S086-2026-2/blob/main/labs/lab02_displays_7seg/imagens/"
local LARGURA = "15cm"

local function arquivo_local(alvo)
  return alvo:match("^%.%./%.%./imagens/([%w_%-]+%.png)$")
end

function Pandoc(doc)
  -- 1ª passada: em qual bloco de nível superior cada imagem aparece por último
  local ultimo = {}
  local ordem = {}
  for i, bloco in ipairs(doc.blocks) do
    pandoc.walk_block(bloco, {
      Link = function(el)
        local nome = arquivo_local(el.target)
        if nome then
          if not ultimo[nome] then table.insert(ordem, nome) end
          ultimo[nome] = i
        end
      end,
    })
  end

  -- 2ª passada: reescreve os links e insere as imagens
  local novos = pandoc.List()
  for i, bloco in ipairs(doc.blocks) do
    novos:insert(pandoc.walk_block(bloco, {
      Link = function(el)
        local nome = arquivo_local(el.target)
        if nome then el.target = BASE .. nome end
        return el
      end,
    }))
    for _, nome in ipairs(ordem) do
      if ultimo[nome] == i then
        local img = pandoc.Image({}, "../../imagens/" .. nome, "", pandoc.Attr("", {}, { width = LARGURA }))
        novos:insert(pandoc.Para({ img }))
      end
    end
  end
  doc.blocks = novos
  return doc
end
