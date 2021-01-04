#include <stdio.h>
#include <malloc.h>
#include "plistlib.h"

double avgList(List L)
{
    double s = 0;
    int count = 0;
    while (L->Next != NULL)
    {
        s += L->Next->Element;
        count++;
        L = L->Next;
    }
    return s / (double)count;
}

int main()
{
    List L;
    makenullList(&L);
    readList(&L);
    printList(L);
    double avg = avgList(L);
    printf("%.3lf", avg);
    return 0;
}