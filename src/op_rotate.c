#include "header.h"

//rotate operations
void ra_left(stack **head, char c);
void rra_right(stack **head, char c);

void ra_left(stack **head, char c)
{
    stack *last;
    stack *newlast;

    // if (!head || !*head || !(*head)->next)
    //     printf("o o \n");
    last = list_getlast(*head);
    newlast = *head;

    (*head)->next->prev = NULL; //second node becomes head
    (*head) = (*head)->next;

    last->next = newlast;
    newlast->prev = last;
    newlast->next = NULL;

// test_print_from_head(*head);

    if(c == 'a')
		printf("ra\n");
	else
		printf("rb\n");
//test_print_from_last(newlast);
//printf("%p\n", (*head)->prev);
    return;
}


void rra_right(stack **head, char c)
{
    stack *last;

    // if (!head || !*head || !(*head)->next)
    //     printf("o o \n");
    last = list_getlast(*head);

    last->prev->next = NULL; //node before last points to NULL

    (*head)->prev = last;
    last->next = (*head);
    last->prev = NULL;

    *head = last;
// last = list_getlast(*head);
// test_print_from_last(last);
    if(c == 'a')
		printf("rra\n");
	else
		printf("rrb\n");
}

