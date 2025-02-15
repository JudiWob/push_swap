#include "header.h"

stack *list_addlast(int data, stack **last, stack **head)
{
	stack *new;
	
	if(*head == NULL) //if first node
	{
		*head = list_newnode(data); //create head
		return (*head); //malloc error included
	}
	
	new =  list_newnode(data); //create new node
	if(!new)
		return (list_free(head), NULL);
	(*last)->next = new;
	new->prev = *last;
	*last = new;
	return *last;

}