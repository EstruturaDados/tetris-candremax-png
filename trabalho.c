#include <stdio.h>
#include <stdlib.h>

#define MAX_FILA 5  // tamanho fixo da fila

// --------- STRUCT DA PEÇA ---------
typedef struct {
    char nome;  // 'I', 'O', 'T', 'L'
    int id;     // identificador único
} Peca;

// --------- VARIÁVEIS DA FILA ---------
Peca fila[MAX_FILA];
int inicio = 0;
int fim = 0;
int quantidade = 0;
int nextID = 0;

// --------- GERA UMA NOVA PEÇA AUTOMÁTICA ---------
Peca gerarPeca() {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca nova;
    nova.nome = tipos[rand() % 4];
    nova.id = nextID++;
    return nova;
}

// --------- INSERE PEÇA (ENQUEUE) ---------
void enqueue() {
    if (quantidade == MAX_FILA) {
        printf("\nA fila está cheia! Nao é possível inserir nova peça.\n");
        return;
    }

    fila[fim] = gerarPeca();
    fim = (fim + 1) % MAX_FILA;
    quantidade++;

    printf("\nPeça inserida com sucesso!\n");
}

// --------- REMOVE PEÇA (DEQUEUE) ---------
void dequeue() {
    if (quantidade == 0) {
        printf("\nA fila está vazia! Nao há peça para jogar.\n");
        return;
    }

    Peca removida = fila[inicio];
    inicio = (inicio + 1) % MAX_FILA;
    quantidade--;

    printf("\nPeça jogada: [%c %d]\n", removida.nome, removida.id);
}

// --------- MOSTRA A FILA ---------
void exibirFila() {
    printf("\n=== Fila de Peças ===\n");

    if (quantidade == 0) {
        printf("A fila está vazia!\n");
        return;
    }

    int i = inicio;
    for (int c = 0; c < quantidade; c++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % MAX_FILA;
    }
    printf("\n");
}

// --------- PROGRAMA PRINCIPAL ---------
int main() {
    srand(time(NULL));

    // Inicializar fila com 5 peças
    for (int i = 0; i < MAX_FILA; i++) {
        enqueue();
    }

    int opcao;

    do {
        exibirFila();
        printf("\nOpções:\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: dequeue(); break;
            case 2: enqueue(); break;
            case 0: printf("\nSaindo do jogo...\n"); break;
            default: printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
