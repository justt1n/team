#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct Node Node;
struct Node
{
    ElementType Element;
    Node *Next;
};

typedef Node *Position;
typedef Position List;

void makenullList(List *pL)
{
    *pL = (List)malloc(sizeof(List));
    (*pL)->Next = NULL;
}

int emptyList(List L)
{
    return L->Next == NULL;
}

Position locate(ElementType x, List L)
{
    Position p = L;
    int found = 0;
    while ((p->Next != NULL) && found == 0)
    {
        if (p->Next->Element == x)
            found = 1;
        else
            p = p->Next;
    }
    return p;
}

void append(int x, List *pL)
{
    Position t, p;
    p = *pL;
    t = (Node *)malloc(sizeof(Node));
    while (p->Next != NULL)
        p = p->Next;
    p->Next = t;
    t->Next = NULL;
    t->Element = x;
}

int member(int x, List L)
{
    int flag = 0;
    while (L->Next != NULL)
    {
        L = L->Next;
        if (L->Element == x)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

void deleteList(Position P, List *pL)
{
    Position Temp;
    if (P->Next != NULL)
    {
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}

void printList(List L)
{
    Position p = L->Next;
    while (p != NULL)
    {
        printf("%d ", p->Element);
        p = p->Next;
    }
    printf("\n");
}

void readList(List *pL)
{
    int n;
    scanf("%d", &n);
    makenullList(pL);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        append(x, pL);
    }
}

void reverse(List *pL)
{
    Position current, previous, next;
    previous = NULL;
    current = *pL;
    while (current != NULL)
    {
        next = current->Next;
        current->Next = previous;
        previous = current;
        current = next;
    }
    *pL = previous;
}

void normalize(List *pL)
{
    Position q, p = (*pL);
    while (p->Next != NULL)
    {
        q = p->Next;
        while (q->Next != NULL)
        {
            if (p->Next->Element == q->Next->Element)
                deleteList(q, pL);
            else
                q = q->Next;
        }
        p = p->Next;
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bbsort(List *pL)
{
    Position p = *pL;
    Position q;
    while (p->Next != NULL)
    {
        q = p->Next;
        while (q->Next != NULL)
        {
            if (p->Next->Element > q->Next->Element)
                swap(&p->Next->Element, &q->Next->Element);
            q = q->Next;
        }
        p = p->Next;
    }
}

void addFirst(int x, List *pL)
{
    Position p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->Element = x;
    p->Next = (*pL)->Next;
    (*pL)->Next = p;
}
