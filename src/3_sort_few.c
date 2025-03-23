/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort_few.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:38:29 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/23 15:41:50 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// sort few
void	sort_two(t_stack *head);
t_stack	*sort_three(t_stack *head);
t_stack	*sort_four(t_stack *head_a);
t_stack	*sort_five(t_stack *head_a);

void	sort_two(t_stack *head)
{
	if (head->data > head->next->data)
		swap_sx(head, 'a');
	return ;
}

t_stack	*sort_three(t_stack *head)
{
	if (head->data > head->next->data && head->data > head->next->next->data)
	{
		rx_left(&head, 'a');
		if (head->data > head->next->data)
			swap_sx(head, 'a');
	}
	else if (head->data < head->next->data
		&& head->next->data > head->next->next->data)
	{
		rrx_right(&head, 'a');
		if (head->data > head->next->data)
			swap_sx(head, 'a');
	}
	else if (head->data > head->next->data)
	{
		swap_sx(head, 'a');
	}
	return (head);
}

t_stack	*sort_four(t_stack *head_a)
{
	t_stack	*head_b;

	head_b = NULL;
	min_to_top(&head_a, 4);
	push_px(&head_a, &head_b, 'a');
	head_a = sort_three(head_a);
	push_px(&head_b, &head_a, 'b');
	return (head_a);
}

t_stack	*sort_five(t_stack *head_a)
{
	t_stack	*head_b;

	head_b = NULL;
	min_to_top(&head_a, 5);
	push_px(&head_a, &head_b, 'b');
	min_to_top(&head_a, 4);
	push_px(&head_a, &head_b, 'b');
	head_a = sort_three(head_a);
	push_px(&head_b, &head_a, 'a');
	push_px(&head_b, &head_a, 'a');
	return (head_a);
}
