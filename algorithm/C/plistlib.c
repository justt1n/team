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

void copyEvenNumbers(List L1, List *pL2)
{
    makenullList(pL2);
    Position p = *pL2;
    while (L1->Next != NULL)
    {
        L1 = L1->Next;
        if (L1->Element % 2 == 0)
        {
            append(L1->Element, &p);
        }
    }
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

List unionSet(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position p = L;
    while (L1->Next != NULL)
    {
        L1 = L1->Next;
        append(L1->Element, &p);
        p = p->Next;
    }
    while (L2->Next != NULL)
    {
        L2 = L2->Next;
        if (member(L2->Element, L) != 1)
        {
            append(L2->Element, &p);
            p = p->Next;
        }
    }
    return L;
}

float getAvg(List L)
{
    float s = 0;
    int count = 0;
    Position p = L;
    if (p->Next != NULL)
    {
        while (p->Next != NULL)
        {
            p = p->Next;
            s += p->Element;
            count++;
        }
        return s / count;
    }
    return -10000;
}

void printList(List L)
{
    Position p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Element);
        p = p->Next;
    }
    printf("\n");
}

void removeAll(int x, List *pL)
{
    Position a = *pL;
    while ((a->Next != NULL))
    {
        Position p = locate(x, a);
        if (p->Next != NULL)
        {
            deleteList(p, &a);
        }
        else
            break;
    }
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
<<<<<<< HEAD
    Position q, p = (*pL);
    while (p->Next != NULL)
    {
        q = p->Next;
        while (q->Next != NULL)
        {
            if (p->Next->Element == q->Next->Element)
=======
    Position q, p = *pL;
    while (p->Next->Next != NULL)
    {
        q = p->Next;
        while (q != NULL)
        {
            if (p->Element == q->Element)
>>>>>>> c478b5bf8ed4c594f8a6f04c813fc0aeacedf4d4
                deleteList(q, pL);
            else
                q = q->Next;
        }
        p = p->Next;
    }
}

<<<<<<< HEAD
void erase(int x, List *pL)
{
    Position p = locate(x, *pL);
    if (p->Next != NULL)
        deleteList(p, pL);
    else
        printf("Not found %d\n", x);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
=======
void addFirst(ElementType x, List *pL)
{
    Position tmp = (*pL)->Next;
    Position p;
    p->Element = x;
    p->Next = tmp;
    free(tmp);
}

List readSet()
{
    List L;
    makenullList(&L);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (member(x, L) == 0)
            addFirst(x, &L);
    }
    return L;
>>>>>>> c478b5bf8ed4c594f8a6f04c813fc0aeacedf4d4
}

void sort(List *pL)
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

List hamHop(List L1, List L2)
{
    List L;
<<<<<<< HEAD
    makenullList(&L);
    Position a = L1;
    Position b = L2;
    while (a->Next != NULL)
    {
        append(a->Element, &L);
        a = a->Next;
    }

    while (b->Next != NULL)
    {
        append(b->Element, &L);
        b = b->Next;
=======
    Position p;
    L = (Node *)malloc(sizeof(Node));
    makenullList(&L);

    append(1, &L);
    append(1, &L);
    append(1, &L);

    normalize(&L);
    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
>>>>>>> c478b5bf8ed4c594f8a6f04c813fc0aeacedf4d4
    }
    normalize(&L);
    return L;
}

int main()
{
    List L1, L2, L;
    makenullList(&L);

    readList(&L1);
    normalize(&L1);
    reverse(&L1);

    readList(&L2);
    normalize(&L2);
    reverse(&L2);

    printList(L1);
    printList(L2);
    L = hamHop(L1, L2);
    printf("%d\n", L->Element);
    printList(L);
}
