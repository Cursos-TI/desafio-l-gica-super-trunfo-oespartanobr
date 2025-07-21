#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.
int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    int populacao1, pontos1;
    float area1, pib1;

    int populacao2, pontos2;
    float area2, pib2;

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    //carta1
    printf("Carta 1\n");
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos1);

    // carta2
    printf("\n Carta 2\n");
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos2);

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    // Exibindo Carta 1
    printf("\nDados da Carta 1\n");
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos turísticos: %d\n\n", pontos1);

    // Exibindo Carta 2
    printf("Dados da Carta 2\n");
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos turísticos: %d\n", pontos2);

    //comparativo por populacao
    if (populacao1 > populacao2) {
        printf("RESULTADO POPULAÇÃO: da Carta 1 ganhou\n");
    } else {
        printf("RESULTADO POPULAÇÃO: Carta 2 ganhou\n");
    }

    //comparativo por area
    if (area1 > area2) {
        printf("RESULTADO AREA: Carta 1 ganhou\n");
    } else {
        printf("RESULTADO AREA: Carta 2 ganhou\n");
    }

    //comparativo por pib
    if (pib1 > pib2) {
        printf("RESULTADO PIB: Carta 1 ganhou\n");
    } else {
        printf("RESULTADO PIB: Carta 2 ganhou\n");
    }

    //comparativo por ponto turistico
    if (pontos1 > pontos2) {
        printf("RESULTADO PONTOS TURISTICOS: Carta 1 ganhou\n");
    } else {
        printf("RESULTADO PONTOS TURISTICOS: Carta 2 ganhou\n");
    }

    return 0;
}
