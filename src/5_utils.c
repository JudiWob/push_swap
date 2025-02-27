#include "header.h"


void smallest_to_b(stack **head_a, stack **head_b, int *argc, int *argb)
{
	int smallest;

	int pos_small;
	int indx_smallest;
//	int max = find_indx_max(*head_a, INT_MAX);

	argb--;
	argc--;
printf("TEST\n");
	smallest = find_indx_min(*head_a, INT_MAX);
	indx_smallest = smallest;
	pos_small = find_pos_index(*head_a, smallest) + indx_smallest;
	//while(!(check_sorting(*head_a) && list_getlast(*head_a)->index == max))
	while(smallest != pos_small)
	{
		pos_small = find_pos_index(*head_a, smallest) + indx_smallest;
		if((smallest != pos_small))
		{
			ra_left(head_a, 'a');
			pos_small--;
		}
	}
	
	push_px(head_a, head_b, 'b');
		//smallest++;
//	}

}


void bubble_sort(stack **head_a);

void bubble_sort(stack **head_a)
{
	int max;
	int min;
	//int mitte;

	int min_pos;

	max = find_indx_max(*head_a, INT_MAX);
	
	int n = 0;
	//what is the lowest index
	min = find_indx_min(*head_a, INT_MAX);
	int save = min;
	printf("min index %i\n", min);
	//where is the lowest index
	
//	printf("min pos %i\n", min_pos);

	while(n < 3)
	{
		min_pos = find_pos_index(*head_a, min) + save;
		while((min != min_pos))
		{
			ra_left(head_a, 'a');
			min_pos--;
		}
		min++;
		n++;
	}
printf("after buubble\n");
test_print_from_head(*head_a, NULL);
		return;
}

void put_max(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize)
{
	int max;
	int min;
	int mitte;

	max = find_indx_max(*head_a, chunksize);
	min = find_indx_min(*head_a, chunksize);
	mitte = find_indx_middle(*head_a, chunksize);

	//while(!(list_getlast(*head_a)->index == max && (*head_a)->index == min ))
	//{
		printf("head index %i\n", (*head_a)->next->index);
		printf("mitte index %i\n", mitte);
		printf("max index %i\n", max);
		while((*head_a)->index != max)
		{
			if((*head_a)->index < mitte)
			{
				if((*head_a)->index > (*head_a)->next->index)
					swap_sx(*head_a, 'a');
				push_px(head_a, head_b, 'b');
				(*argc)--;
				(*argb)++;
			}
			else  //if((*head_a)->index >= mitte)
			{
				printf("\nTEST\n");
				if ((*head_a)->index == max)
				{
					ra_left(head_a, 'a');
					break;
				}
				if(((*head_a)->index < (*head_a)->next->index))
					swap_sx(*head_a, 'a');
					ra_left(head_a, 'a');
			}
		}
		//if((*head_a)->index > list_getlast(*head_a)->index)
		//{
		//&& ((*head_a)->next->index != max)
		//	rra_right(head_a, 'a');
		//	swap_sx(*head_a, 'a');
		//	ra_left(head_a, 'a');
		//	ra_left(head_a, 'a');
		//}
	//}
	return;
}

void check_first_two(stack **head_a, stack **head_b) 
{
printf("check first two\n");
 test_print_from_head(*head_a, *head_b);
    while ((*head_b)->index < (list_getlast(*head_b))->index) //useful if median_a was efficient
        rra_right(head_b, 'b');
	if ((*head_a)->index > (*head_a)->next->index)
		swap_sx(*head_b, 'b');
	if ((*head_b)->index < (*head_b)->next->index)
    	swap_sx(*head_b, 'b');	
printf("after check first two\n");
test_print_from_head(*head_a, *head_b);
	
}
