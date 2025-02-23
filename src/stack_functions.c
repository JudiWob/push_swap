#include "header.h"

int findmax(stack *head)
{
    stack   *max;
    int     n;
    int     pos;

    max = head;
    n = 0;
    pos = 0;
    while(head)
    {
        if(max->data < head->data)
        {
            max = head;
            pos = n;
        }    
        head = head->next;
        n++;
    }
// printf("Pos %i\n", pos);
// printf("Max %i\n", max->data);
    return (pos);
}

int findmin(stack *head)
{
    stack   *min;
    int     n;
    int     pos;

    min = head;
    n = 0;
    pos = 0;
    while(head)
    {
        if(min->data > head->data)
        {
            min = head;
            pos = n;
        }    
        head = head->next;
        n++;
    }
// printf("Pos %i\n", pos);
// printf("Max %i\n", max->data);
    return (pos);
}