#include "header.h"

//min amx ops
int		find_indx_middle(stack *head, int arg);
int     find_pos_max(stack *head);
int     find_pos_min(stack *head);
void	split_median_a(stack **head_a, stack **head_b, int *argc, int *argb);
void	split_median_b(stack **head_a, stack **head_b, int *argc, int *argb);

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
	while(i < *argc && (*argc) > 5)
	{
        if((*head_a)->index <= mitte)
		    {
			    push_px(head_a, head_b, 'a');
			    count++;
                (*argc)--;
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

void	split_median_b(stack **head_a, stack **head_b, int *argc, int *argb)
{
//	int median;
    int i;
    int count;
	int mitte;
    printf("run median b\n");
    count = 0;
    i = 0;
	mitte = find_indx_middle(*head_b, *argb);
// printf("argb: %i\n", *argb);
// printf("argc: %i\n", *argc);
// printf("mitte: %i\n", mitte);
	while(i < *argb && (*argb) > 5)
	{
        if((*head_b)->index > mitte)
		    {
			    push_px(head_b, head_a, 'b');
			    count++;
		    }
		    else
			    ra_left(head_b, 'b');
        i++;
    }
    *argc = *argc + count;
    *argb = (*argb) - count;
//test_print_from_head(*head_a, *head_b);
	return;
}


int find_indx_middle(stack *head, int arg)
{
	stack *temp;
	int mitte;
	int min;
	int max;
	int n;

	temp = head;
	min = head->index;
	max = head->index;
	n = 0;
	while(n < arg && temp)
	{
		if(temp->index > max)
			max = temp->index;
		if(temp->index < min)
			min = temp->index;
		temp = temp->next;
		n++;
	}
// printf("min %i\n", min);
// printf("max %i\n", max);
	mitte = ((max - min) / 2) + min;
//printf("mitte%i\n", mitte);
	if((mitte) % 2 != 0)
		mitte++;
	return (mitte);
// printf("Inside median B:");
// test_print_from_head(head);
// printf("argc/2 %i\n", arg/2);
// printf("max: %i\n", max);
// printf("argc 2: %i\n", argc/2);
// printf("Median: %i\n", median);
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


// int find_median(stack *head, int arg)
// {
// 	mitte = ((*argc) /2);
// 	if((*argc) % 2 != 0)
// 		mitte++;

// }