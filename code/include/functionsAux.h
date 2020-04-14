#ifndef FUNCTIONSAUX_H
#define FUNCTIONSAUX_H

#include "../include/queue.h"
#include "../include/doublyLinkedList.h"
#include "../include/stack.h"

void selecionarDificuldade(char *arquivo);

void desenharMesa(Stack *baralho, Stack *baralho_descarte, List *mao, Queue *tarefas, int *recursos, int turno, int config_suits);

void desenharMenu(int bonus, int config_suits);

void desenharRecursos(int *recursos, int config_suits);

void desenharMao(List *mao, int config_suits);

int desenharTarefas(Queue *q, int completo, int turno, int config_suits);

void adicionarRecursos(int *recursos_totais, int quantidade, int config_suits);

char *converteNaipe(Card carta, int config_suits);

int preencherQuests(Queue *q, char *arquivo);

int preencherBaralho(List *mao, char *arquivo);

void embaralhar(List *mao, Stack *baralho);

void recolherCartas(List *mao, Stack *baralho, Stack *descarte);

void comprarCartas(List *mao, Stack *baralho);

int calcularPontuacaoExtra(List *cartas_descartadas, int recursos_totais[], int config_suits);

#endif
