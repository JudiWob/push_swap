/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_createstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:21:27 by jpaselt           #+#    #+#             */
/*   Updated: 2025/02/20 21:20:35 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//create stack
stack	*createstack(int argc, char **argv);

stack	*createstack(int argc, char **argv)
{
	int 	data;
	stack 	*head_a;
	stack 	*last_a;
	char 	**original_argv;

	head_a = NULL;
	original_argv = argv;
	while(argc > 1) //build list
	{
		argv++;
		argc--;
		if(f_atoi(*argv, &data) == -1) //convert char to int
			clean_exit(&original_argv, argc, head_a, -1); //false character
		last_a = list_addlast(data, &last_a, &head_a); //make node ant store int
//		last_a = NULL;
		if(!last_a)
			clean_exit(&original_argv, argc, head_a, -1); //malloc fail
	}
	if(!check_doubles(head_a))
		clean_exit(&original_argv, argc, head_a, -1); //doubles
	return head_a;
}
