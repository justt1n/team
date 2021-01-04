#include <stdio.h>
#include <iostream>

typedef int KeyType;
struct Node
{
    KeyType Key;
    struct Node *Left, *Right;
};

typedef struct Node *Tree;
void makenullTree(Tree *pT)
{
    *pT = NULL;
}

int emptyTree(Tree T)
{
    return T == NULL;
}

Tree leftChild(Tree n)
{
    if (n != NULL)
        return n->Left;
    else
        return NULL;
}

Tree rightChild(Tree n)
{
    if (n != NULL)
        return n->Right;
    else
        return NULL;
}

int isLeaf(Tree n)
{
    if (n != NULL)
        return (leftChild(n) == NULL) && (rightChild(n) == NULL);
    else
        return 0;
}

void preOrder(Tree T)
{
    printf("%d ", T->Key);
    if (leftChild(T) != NULL)
        preOrder(leftChild(T));
    if (rightChild(T) != NULL)
        preOrder(rightChild(T));
}

void inOrder(Tree T)
{
    if (leftChild(T) != NULL)
        inOrder(leftChild(T));
    printf("%d ", T->Key);
    if (rightChild(T) != NULL)
        inOrder(rightChild(T));
}

void posOrder(Tree T)
{
    if (leftChild(T) != NULL)
        posOrder(leftChild(T));
    if (rightChild(T) != NULL)
        posOrder(rightChild(T));
    printf("%d ", T->Key);
}

int nb_nodes(Tree T)
{
    if (emptyTree(T))
        return 0;
    else
        return 1 + nb_nodes(leftChild(T)) + nb_nodes(rightChild(T));
}

Tree Create2(KeyType v, Tree l, Tree r)
{
    Tree N;
    N = (struct Node *)malloc(sizeof(struct Node));
    N->Key = v;
    N->Left = l;
    N->Right = r;
    return N;
}

Tree search(KeyType x, Tree Root)
{
    if (Root == NULL)
        return NULL;
    else if (Root->Key == x)
        return Root;
    else if (Root->Key < x)
        return search(x, Root->Right);
    else
        return search(x, Root->Left);
}

void insertNode(KeyType x, Tree *pT)
{
    if (*pT == NULL)
    {
    }
}

int main()
{
    return 0;
}