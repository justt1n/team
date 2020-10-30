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
    Position p;
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

void deleteList(Position p, List *pL)
{
    Position Temp, n;
    if (p->Next != NULL)
    {
        Temp->Next = p->Next;
        p->Next = p->Next->Next;
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

void normalize(List *pL)
{
    Position q,p = *pL;
    while(p->Next->Next!= NULL)
    {
        q = p->Next;
        while(q!= NULL)
        {
            if(p->Element == q->Element)
                deleteList(q, pL);
            else
                q = q->Next;
        }
        p = p->Next;
    }
}


int main()
{
    List L;
    Position p;		
    L=(Node *)malloc(sizeof(Node));	
    makenullList(&L);
	
    append(1, &L);
    append(1, &L);
    append(1, &L);

	
    normalize(&L);
    p=L;
    while(p->Next!=NULL)
    {
		printf("%d ",p->Next->Element);
		p=p->Next;
    }
    return 0;
}