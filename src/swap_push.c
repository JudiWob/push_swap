/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:57:33 by tsuno             #+#    #+#             */
/*   Updated: 2025/03/22 14:56:25 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//push and swap operations
void	swap_sx(stack *head, char c);
void	swap_ss(stack *head_a, stack *head_b);
void	push_px(stack **head_take, stack **head_put, char c);
void	rx_left(stack **head, char c);
void	rrx_right(stack **head, char c);

void	swap_sx(stack *head, char c)
{
	if (!head || !head || !head->next) // Check if swap is possible
        return;
	int temp;
	int temp_indx;
	
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;

	temp_indx = head->index;
	head->index = head->next->index;
	head->next->index = temp;
	if(PRINT)
	{
		if(c == ' ')
			return;
		printf("s%c\n", c);
	}	
//test_print_from_head(head);

	return;
}

void	swap_ss(stack *head_a, stack *head_b)
{
	swap_sx(head_a, ' ');
	swap_sx(head_b, ' ');
	if(PRINT)
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

	(*head_put) = save;//update headput
	if(PRINT)
		printf("p%c\n", c);

	return;

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


void rx_left(stack **head, char c)
{
    stack *last;
    stack *newlast;

    if (!head || !*head || !(*head)->next)
        return;
    last = list_getlast(*head);
    newlast = *head;

    (*head)->next->prev = NULL; //second node becomes head
    (*head) = (*head)->next;

    last->next = newlast;
    newlast->prev = last;
    newlast->next = NULL;

    if(PRINT)
       printf("r%c\n", c);
//test_print_from_last(newlast);
//printf("%p\n", (*head)->prev);

    return;
}

void rrx_right(stack **head, char c)
{
    stack *last;

    // if (!head || !*head || !(*head)->next)
    //     printf("o o \n");
    last = list_getlast(*head);

    last->prev->next = NULL; //node before last points to NULL

    (*head)->prev = last;
    last->next = (*head);
    last->prev = NULL;

    *head = last;
// last = list_getlast(*head);
// test_print_from_last(last);
    if(PRINT)
    printf("rr%c\n", c);

    return;
}
