#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct binaryTree
{
    int value;
    struct binaryTree *right;
    struct binaryTree *left;
} **Tree, *NoTree, ElementTree;

Tree createTree(); // cria uma árvore

int treeExist(Tree tree); // árvore existe?

int treeIsEmpty(Tree tree); // árvore vazia?

int addElementTree(Tree tree, int value); // adiciona um elemento à árvore

void delTree(Tree tree); // deleta uma árvore

int heightMaxTree(Tree tree); // obtém a altura máxima da árvore

int heightMinTree(Tree tree); // obtém a altura mínima da árvore

#endif
