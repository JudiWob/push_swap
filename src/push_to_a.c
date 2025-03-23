/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:48:37 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/23 16:49:42 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_to_a(t_stack **head_a, t_stack **head_b, int *argc, int *argb);
void	go_left(t_stack **head_a, t_stack **head_b, int *argc, int *argb);
void	go_right(t_stack **head_a, t_stack **head_b, int *argc, int *argb);
int		find_pos_max(t_stack *head);
int		find_shortest_way(t_stack **head, int argb);

void	push_to_a(t_stack **head_a, t_stack **head_b, int *argc, int *argb)
{
	int	direction;

	if (!*head_b)
		return ;
	direction = find_shortest_way(head_b, *argb);
	if (direction == 1)
		go_left(head_a, head_b, argc, argb);
	else
		go_right(head_a, head_b, argc, argb);
	return ;
}

void	go_right(t_stack **head_a, t_stack **head_b, int *argc, int *argb)
{
	int	max;

	max = find_indx_max(*head_b);
	while (*head_b)
	{
		if ((*head_b)->index == max - 1)
		{
			push_px(head_b, head_a, 'a');
			(*argc)++;
			(*argb)--;
		}
		if ((*head_b)->index == max)
		{
			push_px(head_b, head_a, 'a');
			(*argc)++;
			(*argb)--;
			if ((*head_a) && ((*head_a)->next)
				&& (*head_a)->index > (*head_a)->next->index)
				swap_sx(*head_a, 'a');
			break ;
		}
		if (*head_b)
			rrx_right(head_b, 'b');
	}
}

void	go_left(t_stack **head_a, t_stack **head_b, int *argc, int *argb)
{
	int	max;

	max = find_indx_max(*head_b);
	while (*head_b)
	{
		if ((*head_b)->index == max - 1)
		{
			push_px(head_b, head_a, 'a');
			(*argc)++;
			(*argb)--;
		}
		if ((*head_b)->index == max)
		{
			push_px(head_b, head_a, 'a');
			(*argc)++;
			(*argb)--;
			if ((*head_a) && ((*head_a)->next)
				&& (*head_a)->index > (*head_a)->next->index)
				swap_sx(*head_a, 'a');
			break ;
		}
		if (*head_b)
			rx_left(head_b, 'b');
	}
	return ;
}

int	find_shortest_way(t_stack **head, int argb)
{
	int	pos_max;
	int	direction;

	pos_max = find_pos_max(*head);
	direction = 1;
	if (pos_max > argb / 2)
		direction = 0;
	return (direction);
}

int	find_pos_max(t_stack *head)
{
	t_stack	*max;
	int		n;
	int		pos;

	max = head;
	n = 1;
	pos = 1;
	while (head)
	{
		if (max->data < head->data)
		{
			max = head;
			pos = n;
		}
		head = head->next;
		n++;
	}
	return (pos);
}
