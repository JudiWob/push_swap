#include "header.h"

void test_print_from_head(stack *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}