#include <stdio.h>
#include <malloc.h>
#include "plistlib.h"

void xoaX(int x, List *pL)
{
    Position p = *pL;
    while (p->Next != NULL)
    {
        if (p->Next->Element == x)
        {
            deleteList(p, pL);
            return;
        }
        else
            p = p->Next;
    }
}

int main()
{
    List L;
    makenullList(&L);
    readList(&L);
    int x;
    scanf("%d", &x);
    printList(L);
    xoaX(x, &L);
    printList(L);
    return 0;
}
