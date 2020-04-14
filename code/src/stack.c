#include <stdlib.h>
#include "../include/stack.h"

Stack *createStack()
{
    Stack *new = (Stack *) malloc(sizeof(Stack));
    if (new == NULL)
        return NULL;
    
    new -> last = NULL;

    return new;
}

int stackExist(Stack *s)
{
    if (s == NULL)
        return 0;
    
    return 1;
}

int stackIsEmpty(Stack *s)
{
    if (!stackExist(s))
        return 0;
    
    if (s -> last != NULL)
        return 0;
    
    return 1;
}

int lenStack(Stack *s)
{
    if (!stackExist(s))
        return 0;
    
    if (stackIsEmpty(s))
        return 0;
    
    ElementStack *last = s -> last;

    return last -> posX + 1;
}

int insertElementStack(Stack *s, Card card)
{
    if (!stackExist(s))
        return 0;
    
    ElementStack *new = (ElementStack *) malloc(sizeof(ElementStack));
    if (new == NULL)
        return 0;
    
    new -> main_value = card;
    new -> next = s -> last;
    new -> posX = lenStack(s);

    s -> last = new;

    return 1;
}

int removeElementStack(Stack *s)
{
    if (!stackExist(s))
        return 0;
    
    if (stackIsEmpty(s))
        return 0;
    
    ElementStack *remove = s -> last;

    s -> last = remove -> next;

    free(remove);

    return 1;
}

ElementStack *getElementStack(Stack *s)
{
    if (!stackExist(s))
        return NULL;
    
    if (stackIsEmpty(s))
        return NULL;
    
    return s -> last;
}
