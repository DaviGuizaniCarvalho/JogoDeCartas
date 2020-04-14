#include <stdlib.h>
#include "../include/queue.h"

Queue *createQueue()
{
    Queue *new = (Queue *) malloc(sizeof(Queue));
    if (new == NULL)
        return NULL;
    
    new -> first = NULL;
    new -> last = NULL;

    return new;
}

int queueExist(Queue *q)
{
    if (q == NULL)
        return 0;
    
    return 1;
}

int queueIsEmpty(Queue *q)
{
    if (q -> first != NULL || q -> last != NULL)
        return 0;
    
    return 1;
}

int lenQueue(Queue *q)
{
    if (!queueExist(q))
        return 0;
    
    if (queueIsEmpty(q))
        return 0;
    
    return q -> last -> posX + 1;
}

int insertElementQueue(Queue *q, Quest quest)
{
    if (!queueExist(q))
        return 0;
    
    ElementQueue *new = (ElementQueue *) malloc(sizeof(ElementQueue));
    if (new == NULL)
        return 0;

    new -> main_value = quest;
    new -> posX = lenQueue(q);
    new -> previous = NULL;

    if (queueIsEmpty(q))
    {
        new -> next = NULL;
        q -> first = new;
    }
    else
    {
        new -> next = q -> last;
        new -> next -> previous = new;
    }
    
    q -> last = new;

    return 1;
}

int removeElementQueue(Queue *q)
{
    if (!queueExist(q))
        return 0;
    
    if (queueIsEmpty(q))
        return 0;
    
    ElementQueue *remove = q -> first;

    if (lenQueue(q) == 1)
    {
        q -> first = NULL;
        q -> last = NULL;

        free(remove);
        return 1;
    }

    q -> first = remove -> previous;
    free(remove);

    remove = q -> first;

    remove -> next = NULL;

    while (remove != NULL)
    {
        remove -> posX--;
        remove = remove -> previous;
    }

    return 1;
}

ElementQueue *getElementQueue(Queue *q)
{
    if (!queueExist(q))
        return NULL;
    
    if (queueIsEmpty(q))
        return NULL;
    
    return q -> first;
}
