#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variáveis da Carta 1
    char estado[3], codigo[50], cidade[50];
    int populacao, turisticos;
    float area, pib, densidade, pib_capita;

    // Entrada Carta 1
    printf("Carta 1\n");
    printf("Digite o Estado: ");
    scanf("%s", estado);
    printf("Digite o Código: ");
    scanf("%s", codigo);
    printf("Digite o nome da Cidade: ");
    scanf("%s", cidade);
    printf("Digite a População: ");
    scanf("%d", &populacao);
    printf("Digite a Área: ");
    scanf("%f", &area);
    printf("Digite o PIB: ");
    scanf("%f", &pib);
    printf("Digite os Pontos Turísticos: ");
    scanf("%d", &turisticos);
    
    densidade = populacao / area;
    pib_capita = pib / populacao;

    // Variáveis da Carta 2
    char estado2[3], codigo2[50], cidade2[50];
    int populacao2, turisticos2;
    float area2, pib2, densidade2, pib_capita2;

    // Entrada Carta 2
    printf("\nCarta 2\n");
    printf("Digite o Estado: ");
    scanf("%s", estado2);
    printf("Digite o Código: ");
    scanf("%s", codigo2);
    printf("Digite o nome da Cidade: ");
    scanf("%s", cidade2);
    printf("Digite a População: ");
    scanf("%d", &populacao2);
    printf("Digite a Área: ");
    scanf("%f", &area2);
    printf("Digite o PIB: ");
    scanf("%f", &pib2);
    printf("Digite os Pontos Turísticos: ");
    scanf("%d", &turisticos2);

    densidade2 = populacao2 / area2;
    pib_capita2 = pib2 / populacao2;

    // Menu 
    int atributo1 = 0, atributo2 = 0;

    printf("\n*** Jogo de Comparação ***\n");
    printf("Escolha dois atributos diferentes para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");

    do {
        printf("Escolha o primeiro atributo (1 a 5): ");
        scanf("%d", &atributo1);
    } while (atributo1 < 1 || atributo1 > 5);

    do {
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // Obter valores de cada atributo
    float valor1_c1 = 0, valor2_c1 = 0, valor1_c2 = 0, valor2_c2 = 0;

    // Função auxiliar para buscar valores
    float getValor (int atributo, int pop, float ar, float p, int t, float d) {
        switch (atributo) {
            case 1: return (float)pop;
            case 2: return ar;
            case 3: return p;
            case 4: return (float)t;
            case 5: return d;
            default: return 0;
        }
    }   // DESCULPAS, NAO CONSIGO RESOLVER O ERRO DE ( ";") NO APP DO VISUAL CODE O PROGRAMA RODA NORMAL 

    valor1_c1 = getValor(atributo1, populacao, area, pib, turisticos, densidade);
    valor2_c1 = getValor(atributo2, populacao, area, pib, turisticos, densidade);
    valor1_c2 = getValor(atributo1, populacao2, area2, pib2, turisticos2, densidade2);
    valor2_c2 = getValor(atributo2, populacao2, area2, pib2, turisticos2, densidade2);

    // Mostrar valores comparados
    char* nomes[] = {"", "População", "Área", "PIB", "Pontos Turísticos", "Densidade Demográfica"};

    printf("\nComparando %s e %s\n", cidade, cidade2);
    printf("%s: %.2f vs %.2f\n", nomes[atributo1], valor1_c1, valor1_c2);
    printf("%s: %.2f vs %.2f\n", nomes[atributo2], valor2_c1, valor2_c2);

    
    float soma1 = 0, soma2 = 0;

    // Atributo 1
    if (atributo1 == 5) { // Densidade
        soma1 += (valor1_c1 < valor1_c2) ? 1 : (valor1_c1 > valor1_c2) ? 0 : 0.5;
        soma2 += (valor1_c2 < valor1_c1) ? 1 : (valor1_c2 > valor1_c1) ? 0 : 0.5;
    } else {
        soma1 += (valor1_c1 > valor1_c2) ? 1 : (valor1_c1 < valor1_c2) ? 0 : 0.5;
        soma2 += (valor1_c2 > valor1_c1) ? 1 : (valor1_c2 < valor1_c1) ? 0 : 0.5;
    }

    // Atributo 2
    if (atributo2 == 5) {
        soma1 += (valor2_c1 < valor2_c2) ? 1 : (valor2_c1 > valor2_c2) ? 0 : 0.5;
        soma2 += (valor2_c2 < valor2_c1) ? 1 : (valor2_c2 > valor2_c1) ? 0 : 0.5;
    } else {
        soma1 += (valor2_c1 > valor2_c2) ? 1 : (valor2_c1 < valor2_c2) ? 0 : 0.5;
        soma2 += (valor2_c2 > valor2_c1) ? 1 : (valor2_c2 < valor2_c1) ? 0 : 0.5;
    }

    // Exibir resultado
    printf("\nResultado da comparação:\n");
    if (soma1 > soma2)
        printf("Vencedor: %s\n", cidade);
    else if (soma2 > soma1)
        printf("Vencedor: %s\n", cidade2);
    else
        printf("Empate!\n");

    return 0;
}