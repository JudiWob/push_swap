/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:24:02 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/23 16:25:03 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	min_to_top(t_stack **head_a, int argc);
int		find_pos_min(t_stack *head);

void	min_to_top(t_stack **head_a, int argc)
{
	int	pos_min;

	pos_min = find_pos_min(*head_a);
	if (pos_min == 2)
	{
		swap_sx(*head_a, 'a');
	}
	else if (pos_min == 3)
	{
		rx_left(head_a, 'a');
		rx_left(head_a, 'a');
	}
	else if (pos_min >= 4)
	{
		rrx_right(head_a, 'a');
		if (pos_min == 4 && argc == 5)
			rrx_right(head_a, 'a');
	}
	return ;
}

int	find_pos_min(t_stack *head)
{
	t_stack	*min;
	int		n;
	int		pos;

	min = head;
	n = 1;
	pos = 1;
	while (head)
	{
		if (min->data > head->data)
		{
			min = head;
			pos = n;
		}
		head = head->next;
		n++;
	}
	return (pos);
}
