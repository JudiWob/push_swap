#include "header.h"

//sort utils
void	split_median_a(stack **head_a, stack **head_b, int *argc, int *argb);
void	split_median_b(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize);
void    min_to_top(stack **head_a, int argc);
int     find_pos_min(stack *head);
int     find_pos_index(stack *head, int min_index);
//int     find_pos_max(stack *head);

void	split_median_a(stack **head_a, stack **head_b, int *argc, int *argb)
{
//	int median;
    int i;
    int count;
	int mitte;
    printf("run median a\n");
    count = 0;
    i = 0;
	mitte = find_indx_middle(*head_a, *argc);
//printf("mitte %i a\n", mitte);
//printf("argc %i a\n", *argc);
	while(count < mitte && (*argc) > 5)
	{
        if((*head_a)->index <= mitte)
		    {
// printf("data %i a\n", (*head_a)->data);
// printf("index %i a\n", (*head_a)->index);
                push_px(head_a, head_b, 'a');
			    count++;
                (*argc)--;
//printf("argc %i a\n", *argc);
		    }
		else
			    ra_left(head_a, 'a');
        i++;
    }
    *argb = (*argb) + count;
test_print_from_head(*head_a, *head_b);
// printf("argb: %i\n", *argb);
// printf("argc: %i\n", *argc);
// printf("mitte: %i\n", mitte);
printf("cut\n");
	return;
}

void	split_median_b(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize)
{
    int i;
    int count;
	int mitte;
printf("run median b\n");
    count = 0;
    i = 0;
	mitte = find_indx_middle(*head_b, *argb);
// printf("argb: %i\n", *argb);
// printf("argc: %i\n", *argc);
printf("mitte mitte: %i\n", mitte);
	while(i < *argb && count < chunksize)
	{
        if((*head_b)->index >= mitte)
		{
			if((*head_b)->index < (*head_b)->next->index)
                swap_sx(*head_b, 'b');
            push_px(head_b, head_a, 'b');
			count++;
		}
		else
			ra_left(head_b, 'b');
        i++;
    }
    *argc = *argc + count;
    *argb = (*argb) - count;
    //printf("before rra\n");
    //test_print_from_head(*head_a, *head_b);
    //    while ((*head_b)->index < list_getlast(*head_b)->index)
    //        rra_right(head_b, 'b');
    //printf("after rra\n");
    //test_print_from_head(*head_a, *head_b);
	return;
}

void min_to_top(stack **head_a, int argc)
{
    int pos_min;

    pos_min = find_pos_min(*head_a);

    if (pos_min == 2)
    {
        swap_sx(*head_a, 'a');
    }
    else if (pos_min == 3)
    {
		ra_left(head_a, 'a');
		ra_left(head_a, 'a');
	} 
    else if (pos_min >= 4)
    {
        rra_right(head_a, 'a');
        if(pos_min == 4 && argc == 5)
            rra_right(head_a, 'a');
    }
    //printf("after mintop");
    //test_print_from_head(*head_a, NULL);
    return;
}


int find_pos_index(stack *head, int index)
{
    stack   *min;
    int     pos;

    min = head;
    pos = 0;
    while(head)
    {
        if(head->index == index)
        { 
            return(pos);
        }    
        head = head->next;
        pos++;
    }
// printf("Pos %i\n", pos);
// printf("Max %i\n", max->data);
    return (pos);
}

int find_pos_min(stack *head)
{
    stack   *min;
    int     n;
    int     pos;

    min = head;
    n = 1;
    pos = 1;
    while(head)
    {
        if(min->data > head->data)
        {
            min = head;
            pos = n;
        }    
        head = head->next;
        n++;
    }
// printf("Pos %i\n", pos);
// printf("Max %i\n", max->data);
    return (pos);
}

//int find_pos_max(stack *head)
//{
//    stack   *max;
//    int     n;
//    int     pos;

//    max = head;
//    n = 1;
//    pos = 1;
//    while(head)
//    {
//        if(max->data < head->data)
//        {
//            max = head;
//            pos = n;
//        }    
//        head = head->next;
//        n++;
//    }
//// printf("Pos %i\n", pos);
//// printf("Max %i\n", max->data);
//    return (pos);
//}