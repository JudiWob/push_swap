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

void	sort(stack **head_a, int argc)
{
	stack *head_b;
	
	head_b = NULL;
	if(argc == 2) //sort 2 numbers
		sort_two(*head_a);
	if(argc == 3) //sort 3 numbers
		*head_a = sort_three(*head_a);
	if(argc == 4)
		*head_a = sort_four(*head_a, &head_b);
	
	return;
	

	//need code if argc is only 1
	//if(argc == 4)
}