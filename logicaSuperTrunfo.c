#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char pais[50];
    char estado[50];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

float calcular_densidade(Carta c) {
    return (c.area != 0) ? (float)c.populacao / c.area : 0;
}

float calcular_pib_per_capita(Carta c) {
    return (c.populacao != 0) ? c.pib / c.populacao : 0;
}

void inserir_carta(Carta *c) {
    printf("\n--- Inserir dados da carta ---\n");
    printf("Pais: ");
    scanf(" %[^\n]", c->pais);
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);
    printf("Cidade: ");
    scanf(" %[^\n]", c->cidade);
    printf("Populacao: ");
    scanf("%d", &c->populacao);
    printf("Area (km²): ");
    scanf("%f", &c->area);
    printf("PIB (bilhoes): ");
    scanf("%f", &c->pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &c->pontos_turisticos);
}

void mostrar_carta(Carta c) {
    printf("\n--- Dados da carta ---\n");
    printf("Pais: %s\n", c.pais);
    printf("Estado: %s\n", c.estado);
    printf("Cidade: %s\n", c.cidade);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhoes\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", calcular_densidade(c));
    printf("PIB per capita: %.2f\n", calcular_pib_per_capita(c));
}

int comparar_valores(float v1, float v2, int menor_vence) {
    if (v1 == v2) return 0;  // empate
    if (menor_vence) return (v1 < v2) ? 1 : 2;
    else return (v1 > v2) ? 1 : 2;
}

float pegar_valor(Carta c, int attr) {
    switch (attr) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return calcular_densidade(c);
        default: return 0;
    }
}

const char *nome_atributo(int attr) {
    switch (attr) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        default: return "Invalido";
    }
}

void menu_comparar(Carta c1, Carta c2) {
    int opcao_comp;
    printf("\n=== Menu de Comparação ===\n");
    printf("1 - Comparar 1 atributo\n");
    printf("2 - Comparar 2 atributos\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao_comp);

    if (opcao_comp == 1) {
        int atributo;
        float valor1 = 0, valor2 = 0;
        const char *nome_atrib;

        printf("\n=== Escolha um atributo para comparar ===\n");
        printf("1 - Populacao\n");
        printf("2 - Area\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turisticos\n");
        printf("5 - Densidade Demografica\n");
        printf("Escolha: ");
        scanf("%d", &atributo);

        valor1 = pegar_valor(c1, atributo);
        valor2 = pegar_valor(c2, atributo);
        nome_atrib = nome_atributo(atributo);

        int menor_vence = (atributo == 5) ? 1 : 0;  // Densidade: menor vence, senão maior vence

        printf("\n===== RESULTADO DA COMPARACAO =====\n");
        printf("Carta 1 (%s): %.2f\n", c1.pais, valor1);
        printf("Carta 2 (%s): %.2f\n", c2.pais, valor2);
        printf("Atributo: %s\n", nome_atrib);

        int vencedor = comparar_valores(valor1, valor2, menor_vence);

        if (vencedor == 0) {
            printf(">> Empate no atributo escolhido!\n");
        } else {
            printf(">> Carta %d venceu!\n", vencedor);
        }
    }
    else if (opcao_comp == 2) {
        int attr1, attr2;
        float c1_val1 = 0, c1_val2 = 0, c2_val1 = 0, c2_val2 = 0;

        printf("\n=== Comparar 2 atributos ===\n");
        printf("1 - Populacao\n");
        printf("2 - Area\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turisticos\n");
        printf("5 - Densidade Demografica\n");
        printf("Escolha o primeiro atributo: ");
        scanf("%d", &attr1);
        printf("Escolha o segundo atributo: ");
        scanf("%d", &attr2);

        c1_val1 = pegar_valor(c1, attr1);
        c2_val1 = pegar_valor(c2, attr1);
        c1_val2 = pegar_valor(c1, attr2);
        c2_val2 = pegar_valor(c2, attr2);

        printf("\n===== RESULTADO DA COMPARACAO =====\n");
        printf("Carta 1 (%s): %s = %.2f, %s = %.2f\n",
            c1.pais, nome_atributo(attr1), c1_val1, nome_atributo(attr2), c1_val2);
        printf("Carta 2 (%s): %s = %.2f, %s = %.2f\n",
            c2.pais, nome_atributo(attr1), c2_val1, nome_atributo(attr2), c2_val2);

        // Regra nova:
        // Se Densidade Demografica for um dos atributos, vence quem tiver a menor densidade,
        // independente dos outros valores.
        if (attr1 == 5 || attr2 == 5) {
            float dens1 = calcular_densidade(c1);
            float dens2 = calcular_densidade(c2);
            printf("\nDensidade Demografica usada para decisao final:\n");
            printf("Carta 1: %.2f\n", dens1);
            printf("Carta 2: %.2f\n", dens2);

            int vencedor = comparar_valores(dens1, dens2, 1); // menor vence

            if (vencedor == 0) {
                printf(">> Empate geral na densidade demografica!\n");
            } else {
                printf(">> Carta %d venceu por ter menor densidade demografica!\n", vencedor);
            }
        } else {
            // soma os atributos normalmente
            float soma1 = c1_val1 + c1_val2;
            float soma2 = c2_val1 + c2_val2;

            printf("Soma dos atributos:\n");
            printf("Carta 1: %.2f\n", soma1);
            printf("Carta 2: %.2f\n", soma2);

            if (soma1 == soma2) {
                printf(">> Empate na soma dos atributos!\n");
            } else {
                int vencedor = (soma1 > soma2) ? 1 : 2;
                printf(">> Carta %d venceu!\n", vencedor);
            }
        }
    }
    else {
        printf("Opcao invalida!\n");
    }
}

int main() {
    Carta carta1 = {"", "", "", 0, 0, 0, 0};
    Carta carta2 = {"", "", "", 0, 0, 0, 0};
    int opcao;

    do {
        printf("\n==== JOGO SUPER TRUNFO ====\n");
        printf("1 - Adicionar dados da carta 1\n");
        printf("2 - Adicionar dados da carta 2\n");
        printf("3 - Visualizar dados da carta 1\n");
        printf("4 - Visualizar dados da carta 2\n");
        printf("5 - Comparar as cartas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserir_carta(&carta1);
                break;
            case 2:
                inserir_carta(&carta2);
                break;
            case 3:
                if (strlen(carta1.pais) == 0) {
                    printf("Carta 1 nao possui dados.\n");
                } else {
                    mostrar_carta(carta1);
                }
                break;
            case 4:
                if (strlen(carta2.pais) == 0) {
                    printf("Carta 2 nao possui dados.\n");
                } else {
                    mostrar_carta(carta2);
                }
                break;
            case 5:
                if (strlen(carta1.pais) == 0 || strlen(carta2.pais) == 0) {
                    printf("Ambas as cartas precisam ter dados para comparar.\n");
                } else {
                    menu_comparar(carta1, carta2);
                }
                break;
            case 0:
                printf("Saindo...\n");
                printf("    ######   ######                                                                          ######   ######\n");
                printf("    #   ##   #                                                                               #    #   #    #\n");
                printf("    #   ##   #       #######  #######  #######  #######  #######  #######  #     #  #######  #    #   #    #\n");
                printf("   ##    #  #####    #        #     #  #     #  #     #     #     #     #  ##    #  #     #  #######  #######\n");
                printf("   ##    #  ##       #######  #######  #######  #######     #     #######  # ### #  #     #  ##    #  ##    #\n");
                printf("   ##    #  ##             #  #        #     #  #    #      #     #     #  #    ##  #     #  ##    #  ##    #\n");
                printf("   #######  #######  #######  #        #     #  #    ##     #     #     #  #     #  #######  #######  ##    #\n");

                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}