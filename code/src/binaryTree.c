/*
 *     Author: Davi Guizani Carvalho
 * Date Begin: 01/13/2020 (mm/dd/yyyy)
 *   Date Att: 01/13/2020 (mm/dd/yyyy)
*/

#include <stdlib.h>
#include "../include/binaryTree.h"

Tree createTree() // cria uma árvore
{
    Tree new = (Tree) malloc(sizeof(NoTree));
    if (new == NULL)
        return NULL;
    
    *new = NULL;

    return new;
}

int treeExist(Tree tree) // árvore existe?
{
    if (tree == NULL)
        return 0;
    
    return 1;
}

int treeIsEmpty(Tree tree) // árvore vazia?
{
    if ((*tree) == NULL)
        return 1;
    
    return 0;
}

int addElementTree(Tree tree, int value) // adiciona um elemento à árvore
{
    if (treeIsEmpty(tree))
    {
        NoTree new = (NoTree) malloc(sizeof(ElementTree));
        if (new == NULL)
            return 0;
        
        new -> value = value;
        new -> right = NULL;
        new -> left = NULL;

        (*tree) = new;

        return 1;
    }

    if (value >= (*tree) -> value)
        return addElementTree(&(*tree) -> right, value);

    return addElementTree(&(*tree) -> left, value);
}

void delTree(Tree tree) // deleta uma árvore
{
    if (treeIsEmpty(tree))
        return;
    
    delTree(&(*tree) -> left);
    delTree(&(*tree) -> right);
    free((*tree));
    (*tree) = NULL;
}

int heightMaxTree(Tree tree) // obtém a altura máxima da árvore
{
    if (treeIsEmpty(tree))
        return 0;
    
    int left = heightMaxTree(&(*tree) -> left);
    int right = heightMaxTree(&(*tree) -> right);

    if (right > left)
        return right + 1;
    
    return left + 1;
}

int heightMinTree(Tree tree) // obtém a altura mínima da árvore
{
    if (treeIsEmpty(tree))
        return 0;
    
    int left = heightMinTree(&(*tree) -> left);
    int right = heightMinTree(&(*tree) -> right);

    if (right < left)
        return right + 1;
    
    return left + 1;
}
