#include "header.h"

stack *list_newnode(int data)
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

// int main()
// {
// 	int data = 5;

// 	stack *head;
// 	head = list_new(data);
// 	printf("%d", head->data);
// }