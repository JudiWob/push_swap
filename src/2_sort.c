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
//	int chunk;
	int argb = 0;

	head_b = NULL;

			split_median_a(&head_a, &head_b, &argc, &argb);
printf("Median of A, if smaller, push to b\n");
printf("A:");
test_print_from_head(head_a);
printf("Test B:");
test_print_from_head(head_b);
printf("If A has < 5 Elements, sort manually\n");
			//sort(&head_a, argc);
// printf("A after Sorting: ");
// test_print_from_head(head_a);
			while(argb > 5)
				split_median_b(&head_a, &head_b, &argc, &argb);
			//sort(&head_b, argb);

// printf("Median of B, if bigger, push to b\n");
// printf("A:");
// test_print_from_head(head_a);
// printf("B:");
// test_print_from_head(head_b);

// printf("argc: %i\n", argc);
// printf("argc: %i\n", argc);
// printf("argb: %i\n", argb);
//	push_back_three(&head_a, &head_b, &argc, &argb);

printf("end sort A:");
test_print_from_head(head_a);
printf("end sort B:");
test_print_from_head(head_b);
int count = 0;
printf("%i\n", count++);

	return (head_a);
}

void push_back_three(stack **head_a, stack **head_b, int *argc, int *argb)
{
	//int n = 0;
	int p;
	push_px(head_b, head_a, 'a');
	push_px(head_b, head_a, 'a');
printf("----------\n Inside Push Three\n");
printf("A after 2x push to a:	");
test_print_from_head(*head_a);
printf("B after 2x push to a:	");
test_print_from_head(*head_b);
//printf("argc: %i\n", *argc);
//printf("argb: %i\n", *argb);
		if ((*head_a)->data > (*head_a)->next->data)
		{
			if((*head_b)->data < (*head_b)->next->data)
				swap_ss((*head_a),(*head_b));
			else
				swap_sx(*head_a, 'a');
		}
		//push_px(head_b, head_a, 'a');


printf("A after swapping:	");
test_print_from_head(*head_a);
printf("B after swapping:	");
test_print_from_head(*head_b);	
	p = *argc + *argb;
}

