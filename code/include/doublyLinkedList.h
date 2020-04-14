#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "../include/card.h"

typedef struct elementList
{
    Card main_value;
    int posX;
    struct elementList *previous;
    struct elementList *next;
} ElementList;

typedef struct listDupEnc
{
    ElementList *first;
    ElementList *last;
} List;

List *createList(); // cria uma nova lista

int listIsEmpty(List *l); // verifica se a lista está vazia

int lenList(List *l); // retorna o tamanho da lista

int removeFirstList(List *l); // remove o primeiro elemento da lista

int removeLastList(List *l); // remove o último elemento da lista

int removeIndexList(List *l, int posX); // remove um elemento pelo seu índice

int removeList(List *l); // deleta uma lista

int extendList(List *l1, List *l2); // adiciona os elementos de l2 em l1

int insertFirstList(List *l, Card main_value); // adiciona um elemento no início da lista

int insertLastList(List *l, Card main_value); // adiciona um elemento no final da lista

int insertElementList(List *l, Card main_value, int posX); // insere um elemento em qualquer lugar da lista

ElementList *getElementList(List *l, int posX); // obtem um elemento de uma lista

int randList(List *l); // aleatoriza os elementos da lista

#endif
