#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "TAD.h"

Pilha *criarPilha(){
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->top = NULL;
    return pilha;
}

void inserirTarefa(Pilha *pi, int prioridade, char *idTarefa) {
    printf("\n> > > Inserindo nova tarefa...\n");
    sleep(2);
    if (prioridade < 0 || prioridade > 5) {
        printf("Prioridade inválida! [0 ; 5].\n");
        return;
    }

    // Criar um novo item
    Lista *item = (Lista *)malloc(sizeof(Lista));
    if (item == NULL) {
        printf("Erro ao alocar memória para a nova tarefa!\n");
        return;
    }

    item->prioridade = prioridade;
    item->idTarefa = strdup(idTarefa); // Cria uma cópia da string na memória
    item->dataCriacao = time(NULL);
    item->prox = pi->top;
    pi->top = item;

    printf("> > > Tarefa '%s' com prioridade %d foi inserida com sucesso.\n", idTarefa, prioridade);
}

void listarTarefa(Pilha *pi, int prioridade){
	Lista *item = pi->top;

	if (item){
		printf("\n> > > Listando tarefa com prioridade %d...\n", prioridade);
		do{
			if (item->prioridade == prioridade){
                printf("ID tarefa: %s\t | Prioridade: %d\t | Data criacao: %s", 
                    item->idTarefa, item->prioridade, ctime(&(item->dataCriacao)));
			} 
			item = item->prox;
		} while (item != NULL); 
	} else {
		printf("\n> > > Lista de tarefa vazia");
	}
	
}

void complete(Pilha *pi, char *idTarefa) {
    if (pi->top == NULL) {
        printf("\n> > > Lista de tarefa vazia\n");
        return;
    }

    Lista *item = pi->top;
    Lista *prev = NULL;

    while (item != NULL && strcmp(item->idTarefa, idTarefa) != 0) {
        prev = item;
        item = item->prox;
    }

    if (item == NULL) {
        printf("\n> > > TAREFA INEXISTENTE\n");
        return;
    }

    if (prev == NULL) {
        // Caso seja o primeiro item (topo)
        pi->top = item->prox;
    } else {
        prev->prox = item->prox;
    }

    free(item);

    printf("\n> > > Tarefa '%s' concluída e removida.\n", idTarefa);
}

void freePilha(Pilha *pi) {
    if (pi == NULL) {
        return; 
    }

    Lista *item = pi->top;
    while (item != NULL) {
        Lista *temp = item; 
        item = item->prox; 
        free(temp); 
    }

    free(pi);
}
