/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_createstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:21:27 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/22 16:19:34 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//create stack and indexing
stack	*createstack(int argc, char **argv);

stack	*createstack(int argc, char **argv)
{
	int 	data;
	int		original_argc;
	char 	**original_argv;
	stack 	*head_a;
	stack 	*last_a;
	
	head_a = NULL;
	original_argv = argv;
	original_argc = argc -1;
	while(argc > 1) //build list
	{
		argv++;
		argc--;
		if(!f_atoi(*argv, &data)) 						//convert char *argv to int data
			free_exit(&original_argv, original_argc, head_a, -1); 	//exit: false character
		last_a = list_addlast(data, &last_a, &head_a); 		//make node and store data
		if(!last_a)
			free_exit(&original_argv, original_argc, head_a, -1); 	//exit: malloc fail making node
	}
	if(!check_doubles(head_a))
		free_exit(&original_argv, original_argc, head_a, -1);		//exit:doubles	
	if((check_sorting(head_a)))								
		free_exit(&original_argv, original_argc, head_a, 1);			//exit:already sorted
	return (free_argv(&original_argv, original_argc), head_a);
}


