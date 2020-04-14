#ifndef QUEUE_H
#define QUEUE_H

#include "./quest.h"

typedef struct elementQueue
{
    Quest main_value;
    int posX;
    struct elementQueue *previous;
    struct elementQueue *next;
} ElementQueue;

typedef struct queue
{
    ElementQueue *first;
    ElementQueue *last;
} Queue;

Queue *createQueue();

int queueExist(Queue *q);

int queueIsEmpty(Queue *q);

int lenQueue(Queue *q);

int insertElementQueue(Queue *q, Quest quest);

int removeElementQueue(Queue *q);

ElementQueue *getElementQueue(Queue *q);

#endif
