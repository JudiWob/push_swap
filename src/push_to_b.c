#include "header.h"

int push_to_b(stack **head_a, stack **head_b, int argc, int chunksize);
void push_rest_to_b(stack **head_a, stack **head_b, int *argc);
int ft_remaining(stack *head_a, int min_index, int chunksize_rest);

int push_to_b(stack **head_a, stack **head_b, int argc, int chunksize)
{
	int min_index;
	int count;

	while(argc > chunksize && argc > 30) 
	{
		min_index = find_indx_min(*head_a);
		count = 0;
		while(count < chunksize)
		{
			if((*head_a)->index <= min_index + chunksize -1)
			{
				push_px(head_a, head_b, 'b');
				(argc)--;
				count++;
			}
			else
				rx_left(head_a, 'a');
		}
	}
	push_rest_to_b(head_a, head_b, &argc);
	return(argc);
}


void push_rest_to_b(stack **head_a, stack **head_b, int *argc)
{
	int min_index;
	int count;
	int chunksize_rest;
	int remaining;
	int max_index;

	min_index = find_indx_min(*head_a);
	max_index = find_indx_max(head_a);
	chunksize_rest = *argc/3;
	count = 0;
	while(*argc > 5)
	{
		remaining = ft_remaining(*head_a, min_index, chunksize_rest);
		while(*argc > 5 && count <= chunksize_rest && remaining > 0)
		{
			if((*head_a)->index >= max_index - 4) //99 <= 95
				rx_left(head_a, 'a');
			else if((*head_a)->index <= min_index + chunksize_rest)
			{
				push_px(head_a, head_b, 'b');
				(*argc)--;
				count++;
				remaining--;
			}
			else
				rx_left(head_a, 'a');
		}
		count = 0;
		min_index = find_indx_min(*head_a);
		chunksize_rest = *argc;
	}
	return(sort(head_a, *argc));
}

int ft_remaining(stack *head_a, int min_index, int chunksize_rest)
{
	int count;
	int max_index;
	
	max_index = find_indx_max(head_a);
	count=0;
	while(head_a)
	{
		if(head_a->index <= min_index + chunksize_rest && head_a->index != max_index - 4)
		{
			count++;
		}
		head_a = head_a->next;
	}
	return(count);
}
