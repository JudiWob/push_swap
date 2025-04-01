/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_createstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:50:50 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/30 15:03:42 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack	*createt_stack(int argc, char **argv);

t_stack	*createt_stack(int argc, char **argv)
{
	long	data;
	int		original_argc;
	char	**original_argv;
	t_stack	*head_a;
	t_stack	*last_a;

	head_a = NULL;
	original_argv = argv;
	original_argc = argc - 1;
	while (argc > 1)
	{
		argv++;
		argc--;
		if (!(f_atoi(*argv, &data)))
			free_exit(&original_argv, original_argc, head_a, -1);
		last_a = list_addlast(data, &last_a, &head_a);
		if (!last_a)
			free_exit(&original_argv, original_argc, head_a, -1);
	}
	if (!check_doubles(head_a))
		free_exit(&original_argv, original_argc, head_a, -1);
	if ((check_sorting(head_a)))
		free_exit(&original_argv, original_argc, head_a, 0);
	return (free_argv(&original_argv, original_argc), head_a);
}
