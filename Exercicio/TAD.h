#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct lista {
    char *idTarefa;
    int prioridade;
    time_t dataCriacao;
    struct lista *prox;
} Lista;

typedef struct {
    Lista *top;
} Pilha;

Pilha *criarPilha();

void inserirTarefa(Pilha *pi, int prioridade, char *idTarefa);

void listarTarefa(Pilha *pi, int prioridade);

void complete(Pilha *pi, char *idTarefa);

void freePilha(Pilha *pi);