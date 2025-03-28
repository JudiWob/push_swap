/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:37:11 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/28 15:49:43 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_stack	*head_a;

	argv = split_input(&argc, argv);
	head_a = createt_stack(argc, argv);
	indexing(head_a, argc);
	sort(&head_a, (argc - 1));
	free_list (&head_a);
	return (0);
}
