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
	int data;
	char **original_argv;
	stack *head_a;
	stack *last_a;

	head_a = NULL;
	original_argv = argv; 

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
	printf("vorher argv: %s\n", (*argv));
	clean_exit(&original_argv, argc, head_a);
	printf("nachher argv: %s\n", *original_argv);
	//printf("inside createstack after clean\n");

	if (!head_a && !original_argv)
	{
		printf("2. all free\n");
		exit(EXIT_FAILURE);
	}
	
	//tests
	//test_print_from_head(head_a);
	//printf("------------------------\n");
	//test_print_from_last(last_a);
	//list_free(&head_a);

	return head_a;
}

void clean_exit(char ***argv, int argc, stack *head_a)
{
			//printf("inside clean\n");
			//printf("Vorher argv0: %s\n", (*argv)[0]);
	//*argv = *argv - argc + 1;
			//printf("aritmet argv1: %s\n", (*argv)[1]);
			//printf("aritmet argv1: %s\n", (**argv));
	if((*argv)[0] == NULL)
	{
			//printf("inside 	if((*argv)[0] == NULL)\n");
			//printf("argc %i\n", argc);
		while(argc >= 0)
		{
			//printf("inside loop argv[%i]:%s\n", argc, (*argv)[argc]);
			free((*argv)[argc - 1]);
			argc--;
		}
			//printf("outside loop, argc %i\n", argc);
		free(*argv);
			//printf("outside loop, argc %i\n", argc);
		*argv = NULL;
	}
	
	list_free(&head_a);

	if(!head_a && !(*argv))
		printf("1. all free\n");

	return;
	//exit (EXIT_FAILURE);
}