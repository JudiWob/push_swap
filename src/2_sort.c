/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:34:21 by tsuno             #+#    #+#             */
/*   Updated: 2025/02/20 21:47:59 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//sort general
void	sort(stack **head_a, int argc);
stack 	*sort_big(stack *head_a, int argc);
void	chunking(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize);
void	chunk_sorting(stack **head_a, stack **head_b, int chunksize);

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
//	stack *temp;
	stack *head_b;
	int argb ;

	head_b = NULL;
	argb = 0;
	int chunksize;

	chunksize = 5;
	if (argc > 100)
		chunksize = 10;
	while(argc > 5)
	{
		split_median_a(&head_a, &head_b, &argc, &argb);
		//sort_while_moving(&head_a, &head_b, &argc, &argb);
	}		
	sort(&head_a, argc);
	chunking(&head_a, &head_b, &argc, &argb, chunksize);
test_print_from_head(head_a, head_b);
	chunk_sorting(&head_a, &head_b);
test_print_from_head(head_a, head_b);
	return (head_a);
}

// int argc, int argb
void chunk_sorting(stack **head_a, stack **head_b, int chunksize)
{
	
	
	if ((*head_a)->data > (*head_a)->next->data)
	{
		if((*head_b)->data < (*head_b)->next->data)
			swap_ss(*head_a, *head_b);
		else
			swap_sx(*head_a, 'a');
		
	}

	return;
}


void chunking(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize)
{
	int i;

	i = 0;
	while(i < chunksize && (*argb) > 5)
	{
        push_px(head_b, head_a, 'b');
        i++;
    }
    *argc = *argc + i;
    *argb = (*argb) - i;

	return;
}




// void push_back_three(stack **head_a, stack **head_b, int *argc, int *argb)
// {
// 	//int n = 0;
// 	int p;
// 	push_px(head_b, head_a, 'a');
// 	push_px(head_b, head_a, 'a');
// printf("----------\n Inside Push Three\n");
// printf("A after 2x push to a:	");
// test_print_from_head(*head_a, *head_b);
// //printf("argc: %i\n", *argc);
// //printf("argb: %i\n", *argb);
// 		if ((*head_a)->data > (*head_a)->next->data)
// 		{
// 			if((*head_b)->data < (*head_b)->next->data)
// 				swap_ss((*head_a),(*head_b));
// 			else
// 				swap_sx(*head_a, 'a');
// 		}
// 		//push_px(head_b, head_a, 'a');


// printf("after swapping:	\n");
// test_print_from_head(*head_a, *head_b);	
// 	p = *argc + *argb;
// }

