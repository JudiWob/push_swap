/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:34:21 by tsuno             #+#    #+#             */
/*   Updated: 2025/03/23 16:39:32 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// sort general
void	sort(t_stack **head_a, int argc);
t_stack	*sort_big(t_stack *head_a, int argc);

void	sort(t_stack **head_a, int argc)
{
	if (argc == 2)
		sort_two(*head_a);
	if (argc == 3)
		*head_a = sort_three(*head_a);
	if (argc == 4)
		*head_a = sort_four(*head_a);
	if (argc == 5)
		*head_a = sort_five(*head_a);
	if (argc > 5)
		*head_a = sort_big(*head_a, argc);
	return ;
}

t_stack	*sort_big(t_stack *head_a, int argc)
{
	t_stack	*head_b;
	int		argb;
	int		chunksize;

	head_b = NULL;
	chunksize = argc / 10;
	if (argc <= 100)
		chunksize = 15;
	argb = push_to_b(&head_a, &head_b, argc, chunksize);
	argb = argc - argb;
	while (argb > 0)
	{
		push_to_a(&head_a, &head_b, &argc, &argb);
	}
	return (head_a);
}
