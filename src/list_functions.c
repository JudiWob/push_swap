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
void	test_print_from_head(stack *head)
{
	// if(head == NULL)
	// 	printf(" NULL\n");
	//else
	{
		printf("From Head: ");
		while(head)
		{
			printf("%d ", head->data);
			head = head->next;
		}
		printf("\n");
	}
	return;
}

void	test_print_from_last(stack *last)
{
	printf("From Last: ");
	
	while (last)
	{
		printf("%d ", last->data);
		last = last->prev;
	}
	printf("\n");
	return;
}
