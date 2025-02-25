#include "header.h"

//min amx ops
int		find_median(stack *head, int arg);
int     findmax(stack *head);
int     findmin(stack *head);
void	split_median_a(stack **head_a, stack **head_b, int *argc, int *argb);
void	split_median_b(stack **head_a, stack **head_b, int *argc, int *argb);


void	split_median_a(stack **head_a, stack **head_b, int *argc, int *argb)
{
	int median;
    int i;
    int count;

    count = 0;
    i = 0;
    median = find_median(*head_a, *argc);
//printf("median a: %i\n", median);
//test_print_from_head(*head_a);
	while(i < *argc)
	{
        if((*head_a)->data < median)
		    {
			    push_px(head_a, head_b, 'a');
			    count++;
		    }
		    else
			    ra_left(head_a, 'a');
        i++;
    }
    *argc = *argc - count;
    *argb = (*argb) + count;
//printf("A after split median: ");
printf("median: %i\n", median);
	return;
}
//median = find_median(*head_a, *argc);
// printf("argc: %i\n", *argc);
// printf("i%i\n", i);
    
// printf("Inside split loop A: ");
// test_print_from_head(*head_a);
// printf("Inside split loop B: ");
// test_print_from_head(*head_b);
// printf("median: %i\n", median);

void	split_median_b(stack **head_a, stack **head_b, int *argc, int *argb)
{
	int median;
    int i;
    int count;

    count = 0;
    i = 0;
    median = find_median(*head_b, *argb);
//printf("B before split median: ");
//test_print_from_head(*head_b);
printf("Test B:\n");
printf("median b: %i\n", median);
test_print_from_head(*head_b);
	while(i < *argb)
	{
        if((*head_b)->data > median)
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
printf("Test B:\n");
test_print_from_head(*head_b);
//    printf("B after split median: ");
	return;
}

int find_median(stack *head, int arg)
{
	stack *temp;
    int median;
	int min;
	int max;
	int n;

	temp = head;
	min = head->data;
	max = head->data;
	n = 0;
	while(n < arg && temp)
	{
		if(temp->data > max)
			max = temp->data;
		if(temp->data < min)
			min = temp->data;
		if(n == arg/2)
			median = temp->data;
		temp = temp->next;
		n++;
	}
	return ((min + max + median) / 3);
// printf("min %i\n", min);
// printf("max%i\n", max);
// printf("Inside median B:");
// test_print_from_head(head);
// printf("argc/2 %i\n", arg/2);

// printf("max: %i\n", max);
// printf("argc 2: %i\n", argc/2);
// printf("Median: %i\n", median);
}

int findmax(stack *head)
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

int findmin(stack *head)
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