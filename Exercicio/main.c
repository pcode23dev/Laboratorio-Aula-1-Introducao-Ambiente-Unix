#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "TAD.h"

// Assumindo que as funções inserirTarefa, complete e outras estão implementadas, além das estruturas Pilha e Lista.

int main() {
    Pilha *pi = criarPilha();

    char comando[100];

    printf("< < GERENCIADOR DE TAREFAS > >\n");
    while (1) {
        printf("\nDigite um comando (new <prioridade> <id-tarefa>, list <prioridade>, complete <id-tarefa>, ou 'exit' para sair):\n$ ");
        fgets(comando, sizeof(comando), stdin); // Lê o comando

       
        comando[strcspn(comando, "\n")] = 0;

        if (strncmp(comando, "new", 3) == 0) {
            // Comando new <prioridade> <id-tarefa>
            int prioridade;
            char idTarefa[50];
            strcpy(idTarefa, "");
            if (sscanf(comando, "new %d %s", &prioridade, idTarefa) == 2) {
		        inserirTarefa(pi, prioridade, idTarefa);
            } else {
                printf("Comando inválido! Use: new <prioridade> <id-tarefa>\n");
            }
        } else if (strncmp(comando, "list", 4) == 0) {
            // Comando list <prioridade>
            int prioridade;
            if (sscanf(comando, "list %d", &prioridade) == 1) {
                listarTarefa(pi, prioridade);
            } else {
                printf("Comando inválido! Use: list <prioridade>\n");
            }
        } else if (strncmp(comando, "complete", 8) == 0) {
            // Comando complete <id-tarefa>
            char idTarefa[50];
            if (sscanf(comando, "complete %s", idTarefa) == 1) {
                complete(pi, idTarefa);
            } else {
                printf("Comando inválido! Use: complete <id-tarefa>\n");
            }
        } else if (strcmp(comando, "exit") == 0) {
            printf("Saindo do programa...\n");
            sleep(2);
            freePilha(pi);
            return 0;
        } else {
            printf("Comando desconhecido! Tente novamente.\n");
        }
    }
}
