/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuno <tsuno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:34:21 by tsuno             #+#    #+#             */
/*   Updated: 2025/03/21 11:00:24 by tsuno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//sort general
void	sort(stack **head_a, int argc);
stack 	*sort_big(stack *head_a, int argc);
void	go_short(stack **head_a, int min_index, int chunksize);
int		push_to_b(stack **head_a, stack **head_b, int argc, int chunksize);
void	push_rest_to_b(stack **head_a, stack **head_b, int *argc);
int ft_remaining(stack *head_a, int min_index, int max_index, int chunksize_rest);


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
	chunksize = argc/10;
	if(argc <= 100)
		chunksize = 15;
	
	argb = push_to_b(&head_a, &head_b, argc, chunksize);
	argb = argc - argb;
	
	while(argb > 0)
	{
		push_to_a(&head_a, &head_b, &argc, &argb);
	}	
//printf("after sorting/ before putmax\n");
//test_print_from_head(head_a, head_b);	
 	return (head_a);
 }

int push_to_b(stack **head_a, stack **head_b, int argc, int chunksize)
{
	int min_index;
	//int max_index;
	int count;

	while(argc > chunksize && argc > 30) 
	{
		min_index = find_indx_min(*head_a);
//printf("min index %i\n", min_index);
		count = 0;
		while(count < chunksize)
		{
			if((*head_a)->index <= min_index + chunksize -1)
			{
				push_px(head_a, head_b, 'b');
				(argc)--;
				count++;
			}
			else
				ra_left(head_a, 'a');
				//go_short(head_a, min_index, chunksize);
		}
	}
	min_index = find_indx_min(*head_a);
	
	//printf("argc %i", argc);
	//while(*head_a)
	//push_px(head_a, head_b, 'b');
	//exit(EXIT_FAILURE);
// printf("a %i\n", (*head_a)->index);
// printf("b %i\n", (*head_b)->index);
//test_print_from_head(*head_a, *head_b);	
	push_rest_to_b(head_a, head_b, &argc);
//	test_print_from_head(*head_a, *head_b);	
	return(argc);
}


void push_rest_to_b(stack **head_a, stack **head_b, int *argc)
{
	int max_index;
	int min_index;
	int count;
	int rotate = 0;
	int chunksize_rest;
	int remaining;
//	printf("TEST\n");
	max_index = find_indx_max(*head_a);
	min_index = find_indx_min(*head_a);
	chunksize_rest = *argc/3;
	count = 0;
// exit(EXIT_SUCCESS);
	while(*argc > 5)
	{
// printf("min index %i\n", min_index);
// printf("argc %i\n", *argc);
// printf("chunksize %i\n", chunksize_rest);
	remaining = ft_remaining(*head_a, min_index, max_index, chunksize_rest);
// printf("remain %i\n", remaining);
// test_print_from_head(*head_a, *head_b);
		while(*argc > 5 && count <= chunksize_rest && remaining > 0)
		//while(*argc > 5 && count < chunksize_rest -1  && rotate < *argc)
		{
// printf("count %i\n", count);

// // printf("a %i\n", (*head_a)->index);
// // printf("b %i\n", (*head_b)->index);
// stack *temp = *head_a;
// while(temp)
// {
// 	printf("a %i\n", (temp)->index);
// 	(temp) = (temp)->next;
// }
			if((*head_a)->index >= max_index - 4) //99 <= 95
			{
				//rotate++;
				ra_left(head_a, 'a');
			}	
			else if((*head_a)->index <= min_index + chunksize_rest)
			{
				push_px(head_a, head_b, 'b');
				(*argc)--;
				count++;
				remaining--;
			}
			else
			{
				//rotate++;
				ra_left(head_a, 'a');
			}
		}
		// printf("remain %i\n", remaining);
		count = 0;
		rotate = 0;
		min_index = find_indx_min(*head_a);
		chunksize_rest = *argc;
	}
	return(sort(head_a, *argc));
	
}

int ft_remaining(stack *head_a, int min_index, int max_index, int chunksize_rest)
{
	int count;

	count=0;
	while(head_a)
	{
		if(head_a->index <= min_index + chunksize_rest && head_a->index != max_index - 4)
		{
			count++;
		}
		head_a = head_a->next;
	}
	return(count);
}


//void go_short(stack **head_a, int min_index, int chunksize)
//{
//	int left;
//	int right;
//	int direction;
//	stack *temp;
	
////	printf("TEST\n");
//	temp = *head_a;
//	left = -1;
//	right = -1;
//	while(temp && !(temp->index <= min_index + chunksize))
//	{
//		left++;
//		temp = temp->next;
//	}
//	temp = list_getlast(*head_a);
//	while(temp && !(temp->index <= min_index + chunksize))
//	{
//		right++;
//		temp = temp->prev;
//	}
//	direction = 1;
//	if(right < left)
//		direction = 0;
//	while(*head_a && !((*head_a)->index <= min_index + chunksize))
//	{
//		if(direction == 1)
//			ra_left(head_a, 'a');
//		else
//			rra_right(head_a, 'a');
//		//(*head_a) = (*head_a)->next;
//	}
//}



