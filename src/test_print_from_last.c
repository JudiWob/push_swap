#include "header.h"

void test_print_from_last(stack *last)
{
	while (last)
	{
		printf("Last: %d\n", last->data);
		last = last->prev;
	}

}
