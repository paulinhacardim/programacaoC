#include <stdio.h>

int main() {
    // ===== FASE NOVATO: Cadastro das Cartas =====
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;

    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    int atributo1, atributo2;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    float soma1, soma2;

    // --- Entrada de Dados das Cartas ---
    printf("Cadastro da Carta 1:\n");
    printf("Estado (A a H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta: ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^
]", nomeCidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\nCadastro da Carta 2:\n");
    printf("Estado (A a H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta: ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^
]", nomeCidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // ===== FASE AVENTUREIRO: Calculos =====
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // ===== FASE MESTRE: Menu para escolha de dois atributos =====
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional (Menor vence)\n");
    printf("6 - PIB per Capita\n");

    printf("\nEscolha o PRIMEIRO atributo (1 a 6): ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 6) {
        printf("Opcao invalida!\n");
        return 1;
    }

    do {
        printf("Escolha o SEGUNDO atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 == atributo1)
            printf("Voce nao pode escolher o mesmo atributo duas vezes!\n");
        else if (atributo2 < 1 || atributo2 > 6)
            printf("Opcao invalida!\n");
    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 6);

    // Buscar valores dos atributos selecionados
    for (int i = 1; i <= 2; i++) {
        int attr = (i == 1) ? atributo1 : atributo2;
        switch (attr) {
            case 1:
                (i == 1) ? (valor1_carta1 = populacao1, valor1_carta2 = populacao2) : (valor2_carta1 = populacao1, valor2_carta2 = populacao2);
                break;
            case 2:
                (i == 1) ? (valor1_carta1 = area1, valor1_carta2 = area2) : (valor2_carta1 = area1, valor2_carta2 = area2);
                break;
            case 3:
                (i == 1) ? (valor1_carta1 = pib1, valor1_carta2 = pib2) : (valor2_carta1 = pib1, valor2_carta2 = pib2);
                break;
            case 4:
                (i == 1) ? (valor1_carta1 = pontosTuristicos1, valor1_carta2 = pontosTuristicos2) : (valor2_carta1 = pontosTuristicos1, valor2_carta2 = pontosTuristicos2);
                break;
            case 5:
                (i == 1) ? (valor1_carta1 = densidade1, valor1_carta2 = densidade2) : (valor2_carta1 = densidade1, valor2_carta2 = densidade2);
                break;
            case 6:
                (i == 1) ? (valor1_carta1 = pibPerCapita1, valor1_carta2 = pibPerCapita2) : (valor2_carta1 = pibPerCapita1, valor2_carta2 = pibPerCapita2);
                break;
        }
    }

    // Comparacao dos dois atributos separadamente
    printf("\n=== Comparacao dos Atributos ===\n");

    for (int i = 1; i <= 2; i++) {
        int attr = (i == 1) ? atributo1 : atributo2;
        float v1 = (i == 1) ? valor1_carta1 : valor2_carta1;
        float v2 = (i == 1) ? valor1_carta2 : valor2_carta2;

        printf("\nAtributo %d: ", i);
        switch (attr) {
            case 1: printf("Populacao\n"); break;
            case 2: printf("Area\n"); break;
            case 3: printf("PIB\n"); break;
            case 4: printf("Pontos Turisticos\n"); break;
            case 5: printf("Densidade Populacional (Menor vence)\n"); break;
            case 6: printf("PIB per Capita\n"); break;
        }
        printf("%s: %.2f | %s: %.2f\n", nomeCidade1, v1, nomeCidade2, v2);

        int vencedor;
        if (attr == 5)
            vencedor = (v1 < v2) ? 1 : (v2 < v1) ? 2 : 0;
        else
            vencedor = (v1 > v2) ? 1 : (v2 > v1) ? 2 : 0;

        printf("Vencedor no atributo %d: %s\n", i, vencedor == 1 ? nomeCidade1 : vencedor == 2 ? nomeCidade2 : "Empate");
    }

    // Soma final dos dois atributos
    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    printf("\n=== Resultado Final ===\n");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", nomeCidade1, soma1);
    printf("%s: %.2f\n", nomeCidade2, soma2);

    if (soma1 > soma2)
        printf("Vencedor Final: %s\n", nomeCidade1);
    else if (soma2 > soma1)
        printf("Vencedor Final: %s\n", nomeCidade2);
    else
        printf("Resultado Final: Empate!\n");

    return 0;
}
