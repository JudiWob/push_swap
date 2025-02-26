/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuno <tsuno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:34:21 by tsuno             #+#    #+#             */
/*   Updated: 2025/02/26 17:01:31 by tsuno            ###   ########.fr       */
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

//push all but 5 last numbers from a to b, repeatly sortef by middle index
	while(argc > 5)
	{
		split_median_a(&head_a, &head_b, &argc, &argb);
		//sort_while_moving(&head_a, &head_b, &argc, &argb);
	}		
//sort the five numbers in a
	sort(&head_a, argc);
//check if more than five numbers in b
//push back from b to a chunksize
	//while(argb > 0)
	//{
	chunking(&head_a, &head_b, &argc, &argb, chunksize);
printf("after chunking\n");
test_print_from_head(head_a, head_b);
	//chunk_sorting(&head_a, &head_b, chunksize);
printf("after chunk sorting\n");
test_print_from_head(head_a, head_b);
//	}	
//else: 5 or less number in b
	//else
	//	sort_five_reverse(&head_b, &head_a, argb);
	return (head_a);
}

// int argc, int argb
//void chunk_sorting(stack **head_a, stack **head_b, int chunksize)
//{
//	chunksize = 0;
//	stack *temp_a;
//	stack *temp_b;
	
//	temp_a = head_a;
//	temp_a = head_b;
	
//	int i = 0;
	
//	while(!(check_sorting(head_a)))
//	{
		
//	}
	
//	while (i < chunksize)
//	{

//	}
	
//	if(!(*head_b)->next)
//		return (push_px(head_b, head_a, 'a'));
////looking at a
//	while(1)
//	{
//		while(temp_a)
//		{
//			if
//		}
//	}


//	while((*head_a)->index > list_getlast(head_a)->index)



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
	while(i < chunksize && (*argb) > 0)
	{
        push_px(head_b, head_a, 'a');
		(*argb)--;
        i++;
    }
    *argc = *argc + i;
    //*argb = (*argb) - i;

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

