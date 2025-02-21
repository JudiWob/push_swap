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

//s operations

void swap_one(stack *head, char x)
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
	//only for testing(delete later):
	test_print_from_head(head);
	// 
	//exit (0);
	return;
}

