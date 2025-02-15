#include "header.h"

void test_print_from_head(stack *head)
{
	while(head)
	{
		printf("Head: %d\n", head->data);
		head = head->next;
	}
}