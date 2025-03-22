/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:34:21 by tsuno             #+#    #+#             */
/*   Updated: 2025/03/22 15:05:37 by jpaselt          ###   ########.fr       */
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
