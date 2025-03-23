/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:23:16 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/23 17:21:35 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// index ops
void	indexing(t_stack *head, int argc);
t_stack	*find_no_index(t_stack *temp);
int		find_indx_max(t_stack *head);
int		find_indx_min(t_stack *head);

void	indexing(t_stack *head, int argc)
{
	t_stack	*min_node;
	int		index;

	index = 1;
	while (index <= argc)
	{
		min_node = find_no_index(head);
		if (min_node)
		{
			min_node->index = index;
			index++;
		}
		else
		{
			break ;
		}
	}
	return ;
}

t_stack	*find_no_index(t_stack *temp)
{
	int		min;
	t_stack	*min_node;

	min_node = NULL;
	min = INT_MAX;
	while (temp)
	{
		if (temp->data < min && temp->index == 0)
		{
			min = temp->data;
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

int	find_indx_max(t_stack *head)
{
	t_stack	*temp;
	int		max;

	temp = head;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
		{
			max = temp->index;
		}
		temp = temp->next;
	}
	return (max);
}

int	find_indx_min(t_stack *head)
{
	t_stack	*temp;
	int		min;

	temp = head;
	min = temp->index;
	while (temp)
	{
		if (temp->index < min)
		{
			min = temp->index;
		}
		temp = temp->next;
	}
	return (min);
}
