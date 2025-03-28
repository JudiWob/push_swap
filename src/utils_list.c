/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:23:50 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/23 17:47:40 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack	*list_newnode(long data);
t_stack	*list_addlast(long data, t_stack **last, t_stack **head);
t_stack	*list_getlast(t_stack *head);

t_stack	*list_newnode(long data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*list_addlast(long data, t_stack **last, t_stack **head)
{
	t_stack	*new;

	if (*head == NULL)
	{
		*head = list_newnode(data);
		return (*head);
	}
	new = list_newnode(data);
	if (!new)
		return (NULL);
	(*last)->next = new;
	new->prev = *last;
	*last = new;
	return (*last);
}

t_stack	*list_getlast(t_stack *head)
{
	t_stack	*last;

	last = head;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

/// ////////////////////////////////////////////
void	test_print_from_head(t_stack *a, t_stack *b)
{
	ft_printf("\n t_stack A      t_stack B \n");
	ft_printf("----------------------\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf(" %i", a->data);
			a = a->next;
		}
		else
		{
			ft_printf("      ");
		}
		ft_printf("    |    ");
		if (b)
		{
			ft_printf("%i", b->data);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("----------------------\n");
	return ;
}

void	test_print_from_last(t_stack *last)
{
	ft_printf("\n");
	while (last)
	{
		ft_printf("%i\n", last->data);
		last = last->prev;
	}
	ft_printf("From Last: ");
	return ;
}
