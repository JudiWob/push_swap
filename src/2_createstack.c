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
void	free_exit(char ***argv, int argc, stack *head_a, int success);

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
		if(!f_atoi(*argv, &data)) 						//convert char *argv to int data
			free_exit(&original_argv, argc, head_a, -1); 	//exit: false character
		last_a = list_addlast(data, &last_a, &head_a); 		//make node and store data
//last_a = NULL;
		if(!last_a)
			free_exit(&original_argv, argc, head_a, -1); 	//exit: malloc fail making node
	}
	if(!check_doubles(head_a))
		free_exit(&original_argv, argc, head_a, -1);		//exit:doubles
//	if(!check_sorting(head_a))								
//		free_exit(&original_argv, argc, head_a, 1);			//exit:already sorted

//test_print_from_last(last_a);
//	free_argv(&original_argv, argc);
	return head_a;
}
