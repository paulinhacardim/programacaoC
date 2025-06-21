# Super Trunfo em C: desenvolvendo a lógica do jogo


🃏 Super Trunfo de Cidades - Projeto em C
Este é um projeto em linguagem C que simula um jogo de Super Trunfo de Cidades, com evolução em três níveis de dificuldade: Novato, Aventureiro e Mestre.

📋 Descrição dos Níveis
✅ Nível Novato: Cadastro das Cartas
O programa permite ao usuário cadastrar duas cartas.

Para cada carta, o usuário informa:

Estado (letra de A a H)

Código da Carta (ex: A01, B02)

Nome da Cidade

População

Área (em km²)

PIB (em bilhões de reais)

Número de Pontos Turísticos

O programa exibe os dados de cada carta de forma organizada.

Sem uso de estruturas de repetição ou decisão.

✅ Nível Aventureiro: Cálculo de Densidade Populacional e PIB per Capita
Além do cadastro das cartas:

Calcula a Densidade Populacional: População / Área

Calcula o PIB per Capita: (PIB * 1.000.000.000) / População

Exibe os novos atributos junto com os dados anteriores.

✅ Nível Mestre: Batalha de Cartas + Super Poder
População agora é armazenada como unsigned long int.

Calcula o Super Poder de cada carta, que é a soma de:

População

Área

PIB

Pontos Turísticos

PIB per Capita

Inverso da Densidade Populacional (1 / densidade)

Comparação atributo por atributo, com regras:

Para Densidade Populacional, a menor vence.

Para os demais atributos (incluindo Super Poder), a maior vence.

Exibe o resultado de cada comparação (1 = Carta 1 venceu / 0 = Carta 2 venceu).
