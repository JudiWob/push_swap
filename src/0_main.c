/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:37:11 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/23 18:20:38 by jpaselt          ###   ########.fr       */
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
//	check_sorting(head_a);
//	test_print_from_head(head_a, NULL);
	free_list (&head_a);
	return (0);
}
