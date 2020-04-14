#ifndef CARDS_H
#define CARDS_H

typedef struct card
{
    char face[3];
    char suit;
    int value;
    char name[19];
} Card;

#endif
