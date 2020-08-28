#include <stdio.h>

int top = -1;

int IsFull(int capacity)
{
    if (top >= capacity - 1)
        return 1;
    return 0;
}

int IsEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

void Push(int stack[], int value, int capacity)
{
    if (IsFull(capacity) == 1)
        printf("\nStack is full. Overflow condition!");
    else
    {
        ++top;
        stack[top] = value;
    }
}

void Pop()
{
    if (IsEmpty() == 1)
        printf("\nStack is empty. Underflow condition!");
    else
        --top;
}

int Top(int stack[])
{
    return stack[top];
}

int Size()
{
    return top + 1;
}