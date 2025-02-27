/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuno <tsuno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:34:21 by tsuno             #+#    #+#             */
/*   Updated: 2025/02/27 01:37:44 by tsuno            ###   ########.fr       */
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
test_print_from_head(*head_a, *head_b);
		put_max(head_a, head_b, argc, argb, chunksize);
//		put_max(head_a, head_b, argc, argb, chunksize);

printf("abefore smallest\n");
test_print_from_head(*head_a, *head_b);
		//smallest_to_b(head_a, head_b, argc, argb);
		//bubble_sort(head_a);
		
	//}
	return;
	
}

//	if ((*head_a)->data > (*head_a)->next->data)
//	{
//		if((*head_b)->data < (*head_b)->next->data)
//			swap_ss(*head_a, *head_b);
//		else
//			swap_sx(*head_a, 'a');
//	}
////looking at b
//	//if ((*head_b)->data < (*head_b)->next->data)
//	//{
//		if((*head_b)->data < (*head_b)->next->data) 
//			swap_sx(*head_b, 'b');
//		//else
//		//	swap_sx(*head_a, 'a');
////	}
//	return;
//}


void chunking(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize)
{
	int i;

	i = 0;
	//
	
	split_median_b(head_a, head_b, argc, argb, chunksize);
	//while(i < chunksize && (*argb) > 0)
	//{
    //    push_px(head_b, head_a, 'a');
	//	(*argb)--;
    //    i++;
	//	printf("%i\n", i);
    //}
    //*argc = *argc + i;
    ////*argb = (*argb) - i;
	printf("TEST\n");

	return;
}



