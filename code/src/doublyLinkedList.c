#include <stdlib.h>
#include <time.h>
#include "../include/doublyLinkedList.h"

List *createList() // cria uma nova lista
{
    List *new = (List *) malloc(sizeof(List));

    if (new == NULL)
        return new;

    new -> first = NULL;
    new -> last = NULL;

    return new;
}

int listIsEmpty(List *l) // verifica se a lista está vazia
{
    if (l -> first == NULL || l -> last == NULL)
        return 1;
    
    return 0;
}

int lenList(List *l) // retorna o tamanho da lista
{
    if (listIsEmpty(l))
        return 0;

    ElementList *last = l -> last;

    if (last != NULL)
        return last -> posX + 1;

    return 0;
}

int removeFirstList(List *l) // remove o primeiro elemento da lista
{
    if (listIsEmpty(l))
        return 0;

    ElementList *current = l -> first;
    ElementList *next = current -> next;

    if (next != NULL)
    {
        next -> previous = NULL;
        l -> first = current -> next;
    }
    else
    {
        l -> first = NULL;
        l -> last = NULL;
    }

    free(current);

    current = l -> first;
    while (current != NULL)
    {
        current -> posX--;
        current = current -> next;
    }

    return 1;
}

int removeLastList(List *l) // remove o último elemento da lista
{
    if (listIsEmpty(l))
        return 0;

    ElementList *current = l -> last;
    ElementList *previous = current -> previous;

    if (previous != NULL)
    {
        previous -> next = NULL;
        l -> last = current -> previous;
    }
    else
    {
        l -> first = NULL;
        l -> last = NULL;
    }

    free(current);
    current = NULL;

    return 1;
}

int removeIndexList(List *l, int posX) // remove um elemento pelo seu índice
{
    
    if (listIsEmpty(l) || posX >= lenList(l))
        return 0;

    if (posX < -1)
    {
        posX += lenList(l);
        if (posX < 0)
            return 0;
    }

    if (posX == 0)
        return removeFirstList(l);

    if (posX == -1 || posX == lenList(l) - 1)
        return removeLastList(l);

    ElementList *current = l -> first;
    while (current != NULL && current -> posX < posX)
        current = current -> next;
    
    if (current == NULL)
        return 0;

    ElementList *next = current -> next;
    ElementList *previous = current -> previous;

    previous -> next = next;
    next -> previous = previous;

    free(current);
    current = NULL;

    while (next != NULL)
    {
        next -> posX--;
        next = next -> next;
    }

    return 1;
}

int removeList(List *l) // deleta uma lista
{
    int qty_elements_removed = 0;

    if (listIsEmpty(l))
        return qty_elements_removed;

    ElementList *current = l -> first;

    while (current != NULL)
    {
        free(current -> previous);
        current = current -> next;
        qty_elements_removed++;
    }

    l -> first = NULL;
    l -> last = NULL;

    free(l);
    l = NULL;

    return qty_elements_removed;
}

int extendList(List *l1, List *l2) // adiciona os elementos de l2 em l1
{
    if (listIsEmpty(l1) || listIsEmpty(l1))
        return 0;

    List *new = createList();

    ElementList *first_l2 = l2 -> first;

    if (l1 == l2)
    {
        while (first_l2 != NULL)
        {
            insertLastList(new, first_l2 -> main_value);
            first_l2 = first_l2 -> next;
        }

        first_l2 = new -> first;

        new = NULL;
    }
    else
    {
        free(new);
        new = NULL;
    }

    while (first_l2 != NULL)
    {
        insertLastList(l1, first_l2 -> main_value);
        first_l2 = first_l2 -> next;
    }

    removeList(new);

    return 1;
}

int insertFirstList(List *l, Card main_value) // adiciona um elemento no início
{
    ElementList *new = (ElementList *) malloc(sizeof(ElementList));
    if (new == NULL)
        return 0;

    new -> posX = 0;
    new -> main_value = main_value;
    new -> previous = NULL;

    if (listIsEmpty(l))
    {
        new -> next = NULL;
        l -> first = new;
        l -> last = new;

        return 1;
    }

    ElementList *first = l -> first;

    new -> next = first;

    first -> previous = new;

    l -> first = new;

    new = new -> next;
    while (new != NULL)
    {
        new -> posX++;
        new = new -> next;
    }

    return 1;
}

int insertLastList(List *l, Card main_value) // adiciona um elemento no final da lista
{
    if (listIsEmpty(l))
        return insertFirstList(l, main_value);

    ElementList *new = (ElementList *) malloc(sizeof(ElementList));

    if (new == NULL)
        return 0;

    ElementList *last = l -> last;

    new -> next = NULL;
    new -> previous = l -> last;
    new -> posX = lenList(l);
    new -> main_value = main_value;

    last -> next = new;

    l -> last = new;

    new = NULL;
    last = NULL;

    return 1;
}

int insertElementList(List *l, Card main_value, int posX) // insere um elemento em qualquer lugar da lista
{
    if (listIsEmpty(l))
        return insertFirstList(l, main_value);
    if (posX < -1)
    {
        posX += lenList(l);
        if (posX < 0)
            return insertFirstList(l, main_value);
    }

    if (posX == 0)
        return insertFirstList(l, main_value);
    
    if (posX == -1 || posX >= lenList(l))
        return insertLastList(l, main_value);
    
    ElementList *current = l -> first;
    while (current != NULL && current -> posX < posX)
        current = current -> next;
    
    if (current == NULL)
        return 0;

    ElementList *new = (ElementList *) malloc(sizeof(ElementList));

    if (new == NULL)
        return 0;
    
    new -> main_value = main_value;
    new -> posX = posX;
    new -> next = current;
    new -> previous = current -> previous;
    
    new -> previous -> next = new;

    current -> previous = new;

    new = new -> next;
    while (new != NULL)
    {
        new -> posX++;
        new = new -> next;
    }

    current = NULL;
    new = NULL;

    return 1;
}

ElementList *getElementList(List *l, int posX) // obtem um elemento de uma lista
{
    if (listIsEmpty(l))
        return NULL;
    
    if (posX == 0)
        return l -> first;
    
    if (posX == -1)
        return l -> last;
    
    if (posX < -1)
    {
        posX += lenList(l);
        if (posX < 0)
            return NULL;
    }
    
    ElementList *current = NULL;

    int len_list = lenList(l);
    int inverted = 0;

    if (posX >= len_list || posX < 0)
        return NULL;

    if (posX > len_list / 2)
    {
        current = l -> last;
        inverted = 1;
    }
    else
        current = l -> first;

    while (current != NULL && posX != current -> posX)
    {
        if (inverted)
            current = current -> previous;
        else
            current = current -> next;
    }

    return current;
}

int randList(List *l) // aleatoriza os elementos da lista
{
    if (listIsEmpty(l))
        return 0;

    List *randomized_list = createList();
    if (randomized_list == NULL)
        return 0;

    srand(time(NULL));

    int len_list = lenList(l);

    for (int i = len_list; i > 0; i--)
    {
        int position = rand() % i;

        ElementList *sorted_element = getElementList(l, position);

        if (sorted_element == NULL)
        {
            removeList(randomized_list);
            randomized_list = NULL;
            return 0;
        }
        
        if (!insertLastList(randomized_list, sorted_element -> main_value))
        {
            removeList(randomized_list);
            randomized_list = NULL;
            return 0;
        }
        
        removeIndexList(l, position);
    }

    l -> first = randomized_list -> first;
    l -> last = randomized_list -> last;

    return 1;
}
