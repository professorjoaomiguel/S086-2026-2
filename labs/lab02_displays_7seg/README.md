# Lab 02 - Displays de 7 segmentos

Status: **não testado em bancada**. Os sketches compilam para Arduino UNO R3
(`arduino:avr:uno`), mas ainda não foram validados no Tinkercad nem na bancada.

## Estrutura

- `codigo_base/` - um sketch por etapa (a pasta tem o mesmo nome do `.ino`).
- `verificar_sketches.ps1` - compila todos os sketches; saída 0 se todos compilam.

## Sketches e pinos

| Sketch | Etapa | Ambiente | Pinos |
|---|---|---|---|
| `a1_bcd_cd4511` | 1A | Tinkercad | BCD em D2-D5 (entradas A-D do CD4511) |
| `a2_tabela_segmentos` | 1B | Tinkercad | segmentos a-g em D2-D8 |
| `b1_dois_digitos` | 2A | Tinkercad | segmentos D2-D8; seleção D9, D10 (NPN por dígito) |
| `b2_quatro_digitos` | 2B | Tinkercad | segmentos D2-D8; seleção D9-D12 (NPN por dígito) |
| `b3_contador_millis` | 2C | Tinkercad | igual ao 2B; contador 0000-9999 com `millis()` |
| `c1_tm1637_ola` | 3A | Bancada (UNO R3 + Shield 9-em-1) | CLK = D7, DIO = D8 (a confirmar) |
| `c2_pot_display` | 3B | Bancada | CLK = D7, DIO = D8; potenciômetro em A0 |
| `c3_indicador_nivel` | 3C | Bancada | CLK = D7, DIO = D8; potenciômetro em A0 |

Display de **cátodo comum** (a1, a2, b1-b3): na tabela `SEG[10]`, bit0 = a ...
bit6 = g e 1 = segmento aceso. Nos sketches `b*`, nível alto no pino de seleção
habilita o dígito (base do NPN).

Nomes que os documentos citam: `SEG[10]`, `mostrarDigito(posicao, valor)`,
`exibir[4]` e `varrer()` (b2 e b3).

## Biblioteca (etapas 3A-3C)

- Nome no Gerenciador de Bibliotecas: **TM1637** (autor: Avishay Orpaz, avishorp)
- Versão instalada e testada na compilação: **1.2.0**
- Arquivo de inclusão: `#include <TM1637Display.h>`
- Instalação pela linha de comando: `arduino-cli lib install "TM1637"`

## Verificar

```powershell
./verificar_sketches.ps1
```

Requer `arduino-cli` com o núcleo `arduino:avr` e a biblioteca TM1637 instalados.
