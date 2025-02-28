/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuno <tsuno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:34:21 by tsuno             #+#    #+#             */
/*   Updated: 2025/02/27 03:05:46 by tsuno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//sort general
void	sort(stack **head_a, int argc);
stack 	*sort_big(stack *head_a, int argc);
void	chunking(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize);
void	chunk_sorting(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize);
void check_stack_a(stack **head_a, stack **head_b, int *argc, int *argb);

void	sort(stack **head_a, int argc)
{
	if(argc == 2) 
		sort_two(*head_a);
	if(argc == 3) 
		*head_a = sort_three(*head_a);
	if(argc == 4)
		*head_a = sort_four(*head_a);
	if(argc == 5)
		*head_a = sort_five(*head_a);
	if(argc > 5)
		*head_a = sort_big(*head_a, argc);
//	test_print_from_head(*head_a, NULL);	
	return;
}

stack 	*sort_big(stack *head_a, int argc)
{
	stack *head_b;
	int argb;
	int chunksize;

	head_b = NULL;
	argb = 0;
	chunksize = 5;
	if (argc > 100)
		chunksize = 10;
	
//push all but 5 last numbers from a to b, repeatly sorted by middle index
//test_print_from_head(head_a, head_b);
	//split_median_a(&head_a, &head_b, &argc, &argb);
	//split_median_b(&head_a, &head_b, &argc, &argb);
	//split_median_a(&head_a, &head_b, &argc, &argb);
	//split_median_b(&head_a, &head_b, &argc, &argb);

	while(argc > 5)
	{
		split_median_a(&head_a, &head_b, &argc, &argb);
		//if(argc > 20)
		//	split_median_b(&head_a, &head_b, &argc, &argb);
	}
//sort the five numbers in a
//	printf("TEST ARGC %i\n", argc);
	sort(&head_a, argc);
test_print_from_head(head_a, head_b);	
	check_stack_a(&head_a, &head_b, &argc, &argb);

	while(argb > 0)
	{
		put_max(&head_a, &head_b, &argc, &argb);
		//check_first_two(&head_a, &head_b);
	}	
// 		put_max(&head_a, &head_b, &argc, &argb);
// test_print_from_head(head_a, head_b);	
// 		put_max(&head_a, &head_b, &argc, &argb);
// test_print_from_head(head_a, head_b);	
// 		put_max(&head_a, &head_b, &argc, &argb);

//printf("after sorting/ before putmax\n");
test_print_from_head(head_a, head_b);	

// while(head_a)
// {
// 	printf("Data %i INDEX  %i\n",(head_a)->data, (head_a)->index);
// 	head_a = head_a->next;
// }
	
	check_sorting(head_a);
 	return (head_a);

 }

void check_stack_a(stack **head_a, stack **head_b, int *argc, int *argb)
{
	int max_b;
	int min_a;

	//int smaller_than_max = 1;
	max_b = find_indx_max(*head_b, *argb);
	min_a = find_indx_min(*head_a, *argc);

	if(max_b < min_a)
		return;
	printf("TEST\n");
	while(!(list_getlast(*head_a)->index == min_a))
	{
		if((*head_a)->index == min_a)
			ra_left(head_a, 'a');
		else
		{
			push_px(head_a, head_b, 'b');
			argc--;
			argb++;
		}	
	}
           test_print_from_head(*head_a, *head_b);	
//	printf("min_afound %i\n", min_a);
//	printf("max_B found %i\n", max_b);
	while(max_b > min_a)
	{
		//printf("max_B found %i\n", max_b);
		if((*head_b)->index == max_b && max_b > min_a)
		{
	//printf("HERE\n");
			push_px(head_b, head_a, 'a');
         // printf("argb %i\n", *argb);
        	(*argc)++;
			(*argb)--;
			max_b = find_indx_max(*head_b, *argb);
		}
		else
			ra_left(head_b, 'b');
	}
	rra_right(head_a, 'a');

//	test_print_from_head(*head_a, *head_b);	
}



void chunking(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize)
{
	int i;

	chunksize = 0;
	i = 0;
	
	split_median_b(head_a, head_b, argc, argb);

	//printf("TEST\n");

	return;
}



