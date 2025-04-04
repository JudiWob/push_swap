/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:57:33 by tsuno             #+#    #+#             */
/*   Updated: 2025/03/30 14:58:18 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// push and swap operations
void	swap_sx(t_stack *head, char c);
void	push_px(t_stack **head_take, t_stack **head_put, char c);
void	rx_left(t_stack **head, char c);
void	rrx_right(t_stack **head, char c);

void	swap_sx(t_stack *head, char c)
{
	int	temp;
	int	temp_indx;

	if (!head || !head || !head->next)
		return ;
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	temp_indx = head->index;
	head->index = head->next->index;
	head->next->index = temp;
	if (PRINT)
	{
		if (c == ' ')
			return ;
		ft_printf("s%c\n", c);
	}
	return ;
}

void	push_px(t_stack **head_take, t_stack **head_put, char c)
{
	t_stack	*save;

	if (!(*head_take))
		return ;
	save = (*head_take);
	(*head_take) = (*head_take)->next;
	if (*head_take)
		(*head_take)->prev = NULL;
	save->next = *head_put;
	if (*head_put)
		(*head_put)->prev = save;
	(*head_put) = save;
	if (PRINT)
		ft_printf("p%c\n", c);
	return ;
}

void	rx_left(t_stack **head, char c)
{
	t_stack	*last;
	t_stack	*newlast;

	if (!head || !*head || !(*head)->next)
		return ;
	last = list_getlast(*head);
	newlast = *head;
	(*head)->next->prev = NULL;
	(*head) = (*head)->next;
	last->next = newlast;
	newlast->prev = last;
	newlast->next = NULL;
	if (PRINT)
		ft_printf("r%c\n", c);
	return ;
}

void	rrx_right(t_stack **head, char c)
{
	t_stack	*last;

	last = list_getlast(*head);
	last->prev->next = NULL;
	(*head)->prev = last;
	last->next = (*head);
	last->prev = NULL;
	*head = last;
	if (PRINT)
		ft_printf("rr%c\n", c);
	return ;
}
