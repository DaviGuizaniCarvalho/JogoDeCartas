#ifndef STACK_H
#define STACK_H

#include "./card.h"

typedef struct elementStack
{
    Card main_value;
    int posX;
    struct elementStack *next;
} ElementStack;

typedef struct stack
{
    ElementStack *last;
} Stack;

Stack *createStack();

int stackExist(Stack *s);

int stackIsEmpty(Stack *s);

int lenStack(Stack *s);

int insertElementStack(Stack *s, Card card);

int removeElementStack(Stack *s);

ElementStack *getElementStack(Stack *s);

#endif
