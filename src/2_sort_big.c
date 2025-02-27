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

void	sort(stack **head_a, int argc)
{
	test_print_from_head(*head_a, NULL);	
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
	test_print_from_head(*head_a, NULL);	
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
	while(argc > 5)
	{
		split_median_a(&head_a, &head_b, &argc, &argb);
	}		
//sort the five numbers in a
	sort(&head_a, argc);
printf("after sorting\n");
	test_print_from_head(head_a, head_b);	

//check if more than five numbers in b
//push back from b to a chunksize
//	while(argb > 0)
//	{
		chunking(&head_a, &head_b, &argc, &argb, chunksize);
printf("after chunking\n");
test_print_from_head(head_a, head_b);
		chunk_sorting(&head_a, &head_b, &argc, &argb, chunksize);
//printf("after chunk sorting\n");
//test_print_from_head(head_a, head_b);
//	}	
//else: 5 or less number in b
//else
//	sort_five_reverse(&head_b, &head_a, argb);
printf("END OF SORTING BIG:\n");
test_print_from_head(head_a, head_b);
	return (head_a);
}

// int argc, int argb
void chunk_sorting(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize)
{
	//	stack *temp_a;
	//	stack *temp_b;
	
	//	temp_a = head_a;
	//	temp_a = head_b;
	//chunksize = 0;
	//while(!check_sorting(*head_a))
	//{
		check_first_two(head_a, head_b);
printf("before put max\n");
//printf("head indes %i", (*head_a)->next->index);
//printf("last indes %i", (list_getlast((*head_a))->index));
test_print_from_head(*head_a, *head_b);
	
		put_max(head_a, head_b, argc, argb, chunksize);
printf("after first put max\n");
test_print_from_head(*head_a, *head_b);
chunksize--;
printf("chunksize %i\n", chunksize);
		put_max(head_a, head_b, argc, argb, chunksize);
printf("put max\n");
test_print_from_head(*head_a, *head_b);
chunksize--;
		put_max(head_a, head_b, argc, argb, chunksize);
printf("abefore smallest\n");
test_print_from_head(*head_a, *head_b);
//split_median_a(head_a, head_b, argc, argb);
		//smallest_to_b(head_a, head_b, argc, argb);
		//bubble_sort(head_a);
		
	//}
	return;
	
}



void chunking(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize)
{
	int i;

	i = 0;
	
	split_median_b(head_a, head_b, argc, argb, chunksize);

	printf("TEST\n");

	return;
}



