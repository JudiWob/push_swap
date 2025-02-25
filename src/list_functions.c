#include "header.h"

//list functions
stack	*list_newnode(int data);
stack	*list_addlast(int data, stack **last, stack **head);
stack	*list_getlast(stack *head);

stack	*list_newnode(int data)
{
	stack *new;

	new = malloc(sizeof(stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

stack	*list_addlast(int data, stack **last, stack **head)
{
	stack *new;
	
	if(*head == NULL) //if first node
	{
		*head = list_newnode(data); //create head
		return (*head); //malloc error included
	}
	new =  list_newnode(data); //create new node
	if(!new)
		return (printf("fail toooo create stack\n"),new);
	(*last)->next = new; //connect last to new
	new->prev = *last; //connect new to last
	*last = new; //update last node 
	return *last;
}

stack *list_getlast(stack *head)
{
	stack *last;
	
	last = head;
	while(last->next)
	{
		last = last->next;
	}
	return (last);
}



/// ////////////////////////////////////////////
void	test_print_from_head(stack *a, stack *b)
{
	// if(head == NULL)
	// 	printf(" NULL\n");
	//else
	printf("\n Stack A      Stack B \n");
    printf("----------------------\n");

    // Iterate through both stacks simultaneously
    while (a || b) {
        if (a) {
            printf(" %5d", a->data);
            a = a->next;
        } else {
            printf("      "); // Empty space if Stack A is shorter
        }

        printf("    |    "); // Separator

        if (b) {
            printf("%5d", b->data);
            b = b->next;
        }

        printf("\n"); // Newline for the next row
    }
    
    printf("----------------------\n");
	return;
}

void	test_print_from_last(stack *last)
{
	printf("\n");
	
	while (last)
	{
		printf("%d\n", last->data);
		last = last->prev;
	}
	printf("From Last: ");
	return;
}
