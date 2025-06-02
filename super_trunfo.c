#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CIDADE 50
#define MAX_CODIGO 4

typedef struct {
    char estado;
    char codigo[MAX_CODIGO + 1];
    char cidade[MAX_CIDADE + 1];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade; 
    float pib_per_capita; 
} Carta;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrar_carta(Carta *carta, int indice) {
    printf("\n=== Cadastro da Carta %d ===\n", indice + 1);

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);
    carta->estado = toupper(carta->estado);
    limpar_buffer();

    printf("Codigo da Carta (ex: A01): ");
    scanf("%4s", carta->codigo);
    limpar_buffer();

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->cidade);
    limpar_buffer();

    printf("Populacao, Area, PIB, Pontos Turisticos (separados por espaco):\n");
    scanf("%d %f %f %d", &carta->populacao, &carta->area, &carta->pib, &carta->pontos_turisticos);
    limpar_buffer();

    carta->densidade = (carta->area > 0) ? (float)carta->populacao / carta->area : 0;
    carta->pib_per_capita = (carta->populacao > 0) ? carta->pib / carta->populacao : 0;
}

void exibir_carta(const Carta *carta, int indice) {
    printf("\n=== Carta %d ===\n", indice + 1);
    printf("Estado: %c\n", carta->estado);
    printf("Codigo: %s\n", carta->codigo);
    printf("Cidade: %s\n", carta->cidade);
    printf("Populacao: %d\n", carta->populacao);
    printf("Area: %.2f km2\n", carta->area);
    printf("PIB: %.2f bilhoes de reais\n", carta->pib);
    printf("Pontos Turisticos: %d\n", carta->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta->densidade);
    printf("PIB per Capita: %.2f bilhoes/hab\n", carta->pib_per_capita);
}

void comparar_cartas(const Carta *carta1, const Carta *carta2) {
    printf("\n=== Comparacao de Populacao ===\n");
    if (carta1->populacao > carta2->populacao) {
        printf("%s tem maior populacao que %s!\n", carta1->cidade, carta2->cidade);
    } else if (carta1->populacao < carta2->populacao) {
        printf("%s tem maior populacao que %s!\n", carta2->cidade, carta1->cidade);
    } else {
        printf("As cidades %s e %s tem a mesma populacao!\n", carta1->cidade, carta2->cidade);
    }
}

int main() {
    Carta cartas[2];

    for (int i = 0; i < 2; i++) {
        cadastrar_carta(&cartas[i], i);
    }

    for (int i = 0; i < 2; i++) {
        exibir_carta(&cartas[i], i);
    }

    comparar_cartas(&cartas[0], &cartas[1]);

    return 0;
}