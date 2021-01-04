#include <stdio.h>
#include <malloc.h>
#include "plistlib.h"

List readSet1()
{
    List L;
    makenullList(&L);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if (member(tmp, L) == 0)
            addFirst(tmp, &L);
    }
    return L;
}

List hamHop(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position pL1 = L1->Next;
    Position pL2 = L2->Next;

    while (pL1 != NULL)
    {
        append(pL1->Element, &L);
        pL1 = pL1->Next;
    }
    while (pL2 != NULL)
    {
        if (member(pL2->Element, L) == 0)
            append(pL2->Element, &L);
        pL2 = pL2->Next;
    }
    return L;
}

int main()
{
    List L1;
    makenullList(&L1);
    L1 = readSet1();
    printList(L1);

    List L2;
    makenullList(&L2);
    L2 = readSet1();
    printList(L2);

    List L;
    makenullList(&L);
    L = hamHop(L1, L2);
    printList(L);
    return 0;
}
