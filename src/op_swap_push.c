/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s__sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:57:33 by tsuno             #+#    #+#             */
/*   Updated: 2025/02/20 21:52:01 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//swap operations
void	swap_sx(stack *head, char x);
void	swap_ss(stack *head_a, stack *head_b);
void	push_px(stack **head_take, stack **head_put, char c);

void	swap_sx(stack *head, char x)
{
	if (!head || !head || !head->next) // Check if swap is possible
        return;
	int temp;
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	if(x == 'a')
		printf("sa\n");
	else
		printf("sb\n");
//test_print_from_head(head);
	return;
}

void	swap_ss(stack *head_a, stack *head_b)
{
	swap_sx(head_a, ' ');
	swap_sx(head_b, ' ');
	printf("ss\n");
	return;
}

void	push_px(stack **head_take, stack **head_put, char c)
{
	stack *save;

	if(!(*head_take))
		return;
	save = (*head_take);				// save head to push
	(*head_take) = (*head_take)->next; 	// update head, could be NULL if only one element in stack

	if (*head_take)						// if > 1 node in stack, cut head of
        (*head_take)->prev = NULL;

	save->next = *head_put;				// put save infront of head_put
	//save->prev = NULL;				// is always NULL

	if (*head_put)						// if put has nodes
        (*head_put)->prev = save;		//connect both ways

	(*head_put) = save;					//update headput
	printf("p%c\n", c);

// if(!*head_take)
// {
// 	printf("Stack take is empty\n");
// 	return;
// }	
// printf("A:");
// test_print_from_last(list_getlast(*head_take));
// printf("A:");
// test_print_from_head(*head_take);
// printf("B:");
// test_print_from_last(list_getlast(*head_put));
// printf("B:");
// test_print_from_head(*head_put);
}


