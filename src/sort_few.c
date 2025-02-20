/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:38:29 by jpaselt           #+#    #+#             */
/*   Updated: 2025/02/20 21:49:15 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//sort few

void sort_two(stack *head_a)
{
	if(head_a->data > head_a->next->data)
			sx_swap(head_a, 'a');
}

// void sort_three(stack *head_a)
// {
 
// }