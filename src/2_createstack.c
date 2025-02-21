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

void freeargv(char ***argv, int argc);

stack *createstack(int argc, char **argv)
{
	int 	data;
	stack 	*head_a;
	stack 	*last_a;

	head_a = NULL;
	while(argc > 1) //build list
	{
		argv++;
		argc--;
		if(f_atoi(*argv, &data) == 0) 
			clean_exit(&argv, argc, head_a); //false character
		last_a = list_addlast(data, &last_a, &head_a);
		if(!last_a)
			clean_exit(&argv, argc, head_a); //malloc fail
	}
	
	//tests
	//test_print_from_head(head_a);
	//printf("------------------------\n");
	//test_print_from_last(last_a);
	//list_free(&head_a);
	
	return head_a;
}


// char **original_argv;
// original_argv = argv; 
// if (!head_a && !original_argv)
// {
// 	printf("2. all free\n");
// 	exit(EXIT_FAILURE);
// }