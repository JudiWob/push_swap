#include "header.h"

//
void put_max(stack **head_a, stack **head_b, int *argc, int *argb);
void go_left_max(stack **head_a, stack **head_b, int *argc, int *argb);
void go_right_max(stack **head_a, stack **head_b, int *argc, int *argb);
int find_pos_max(stack *head);
int find_shortest_way(stack **head, int argb);

void put_max(stack **head_a, stack **head_b, int *argc, int *argb)
{

    int direction;

    if(!*head_b)
        return;

	direction = find_shortest_way(head_b, *argb);
    if(direction == 1)
        go_left_max(head_a, head_b, argc, argb);
    else 
        go_right_max(head_a, head_b, argc, argb);

    
	return;
}

void go_right_max(stack **head_a, stack **head_b, int *argc, int *argb)
{
    int max;
 //   int smaller_than_max;

    max = find_indx_max(*head_b, INT_MAX);
//printf("go max right index %i\n", max);
 //   smaller_than_max = 1;
//printf("go max right head data %i index %i\n", (*head_b)->data, (*head_b)->index);
//printf("go max right head next data %i index %i\n", (*head_b)->next->data, (*head_b)->next->index);
    while(1) //&& (*head_a)->index == min )
	{
        // while((*head_b)->index == (max - smaller_than_max) && smaller_than_max <= 2)
		// {
		// 	push_px(head_b, head_a, 'a');
		// 	ra_left(head_a, 'a');
		// 	(*argc)++;
		// 	(*argb)--;
		// 	smaller_than_max++;
		// }
		if((*head_b)->index == max)
		{
			push_px(head_b, head_a, 'a');
// printf("smaller_than_max when max found %i\n", smaller_than_max);
           // test_print_from_head(*head_a, *head_b);	
         // printf("argb %i\n", *argb);
			// while(smaller_than_max > 1)
			// {
			// 	rra_right(head_a, 'a');
			// 	smaller_than_max--;
            //     check_first_two(head_a, head_b);

			// }
           // check_first_two(head_a, head_b);
            (*argc)++;
			(*argb)--;
            break;
		}
		rra_right(head_b, 'b');
 //printf("head b index %i\n", (*head_b)->index);
	}
    
}

void go_left_max(stack **head_a, stack **head_b, int *argc, int *argb)
{
    int max;
    int smaller_than_max;

    max = find_indx_max(*head_b, INT_MAX);
//printf("go max left, max index = %i\n", max);
//test_print_from_head(*head_a, *head_b);	
    smaller_than_max = 1;
//printf("go max head data %i index %i\n", (*head_b)->data, (*head_b)->index);
//printf("go max head next data %i index %i\n", (*head_b)->next->data, (*head_b)->next->index);
    while(1) //&& (*head_a)->index == min )
	{
        while((*head_b)->index == (max - smaller_than_max) && smaller_than_max <= 2)
		{
			push_px(head_b, head_a, 'a');
				// if((*head_a)->index > (*head_a)->next->index)
				// 	swap_sx(*head_a, 'a');
			ra_left(head_a, 'a');
			(*argc)++;
			(*argb)--;
			smaller_than_max++;
		}
		if((*head_b)->index == max)
		{
			push_px(head_b, head_a, 'a');
			while(smaller_than_max > 1)
			{
				rra_right(head_a, 'a');
				smaller_than_max--;
               // check_first_two(head_a, head_b);
                if ((*head_a)->index > (*head_a)->next->index)
		            swap_sx(*head_a, 'a');
			}
            (*argc)++;
			(*argb)--;
    //printf("TEST Found MAX\n");
    //   test_print_from_head(*head_a, *head_b);	
            break;
		}
		ra_left(head_b, 'a');
       // test_print_from_head(*head_a, *head_b);	
	}
}

int find_shortest_way(stack **head, int argb)
{
    int pos_max;

    pos_max = find_pos_max(*head);

    int direction;

    direction = 1;

    if( pos_max > argb/2)
        direction = 0;

    return (direction);
}

int find_pos_max(stack *head)
{
   stack   *max;
   int     n;
   int     pos;

   max = head;
   n = 1;
   pos = 1;
   while(head)
   {
       if(max->data < head->data)
       {
           max = head;
           pos = n;
       }    
       head = head->next;
       n++;
   }
//printf("Pos %i\n", pos);
//printf("Max %i\n", max->data);
   return (pos);
}