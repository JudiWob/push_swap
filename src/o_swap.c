/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuno <tsuno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:57:33 by tsuno             #+#    #+#             */
/*   Updated: 2025/02/18 20:34:17 by tsuno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap_a(stack *head_a)
{
	if (!head_a || !head_a || !head_a->next) // Check if swap is possible
        return;
	
	stack *temp;
	
	
	temp = head_a->next;
	
	head_a->prev = temp;
	head_a->next = NULL;
	
	temp->next = head_a;
	temp->prev = NULL;
	
	return head_a;
	
}