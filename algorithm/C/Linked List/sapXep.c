#include <stdio.h>
#include <malloc.h>
#include "plistlib.h"

void bbSort(List *pL)
{
    Position a = (*pL);
    
    while (a->Next != NULL)
    {
    	Position b = (*pL)->Next;
        while (b->Next != NULL)
        {
            if (b->Element > b->Next->Element)
                swap(&b->Element, &b->Next->Element);
            b = b->Next;
        }
        a = a->Next;
    }
}

int main()
{
    List L;
    makenullList(&L);
    readList(&L);
    printList(L);
    bbSort(&L);
    printList(L);
    return 0;
}
