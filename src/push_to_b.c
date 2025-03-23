/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:22:59 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/23 16:40:23 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		push_to_b(t_stack **head_a, t_stack **head_b, int argc, int chunksize);
void	push_rest_to_b(t_stack **head_a, t_stack **head_b, int *argc);
int		ft_remaining(t_stack *head_a, int min_index, int chunksize);
void	loop(t_stack **head_a, t_stack **head_b, int *argc, int chunksize);

int	push_to_b(t_stack **head_a, t_stack **head_b, int argc, int chunksize)
{
	int	min_index;
	int	count;

	while (argc > chunksize && argc > 30)
	{
		min_index = find_indx_min(*head_a);
		count = 0;
		while (count < chunksize)
		{
			if ((*head_a)->index <= min_index + chunksize - 1)
			{
				push_px(head_a, head_b, 'b');
				(argc)--;
				count++;
			}
			else
				rx_left(head_a, 'a');
		}
	}
	push_rest_to_b(head_a, head_b, &argc);
	return (argc);
}

void	push_rest_to_b(t_stack **head_a, t_stack **head_b, int *argc)
{
	int	min_index;
	int	chunksize;

	min_index = find_indx_min(*head_a);
	chunksize = *argc / 3;
	while (*argc > 5)
	{
		loop(head_a, head_b, argc, chunksize);
		min_index = find_indx_min(*head_a);
		chunksize = *argc;
	}
	return (sort(head_a, *argc));
}

void	loop(t_stack **head_a, t_stack **head_b, int *argc, int chunksize)
{
	int	count;
	int	remaining;
	int	max_index;
	int	min_index;

	count = 0;
	max_index = find_indx_max(*head_a);
	min_index = find_indx_min(*head_a);
	remaining = ft_remaining(*head_a, min_index, chunksize);
	while (*argc > 5 && count <= chunksize && remaining > 0)
	{
		if ((*head_a)->index >= max_index - 4)
			rx_left(head_a, 'a');
		else if ((*head_a)->index <= min_index + chunksize)
		{
			push_px(head_a, head_b, 'b');
			(*argc)--;
			count++;
			remaining--;
		}
		else
			rx_left(head_a, 'a');
	}
}

int	ft_remaining(t_stack *head_a, int min_index, int chunksize)
{
	int	count;
	int	max_index;

	max_index = find_indx_max(head_a);
	count = 0;
	while (head_a)
	{
		if (head_a->index <= min_index + chunksize
			&& head_a->index != max_index - 4)
		{
			count++;
		}
		head_a = head_a->next;
	}
	return (count);
}
