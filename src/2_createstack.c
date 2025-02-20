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

stack *createstack(int argc, char **argv)
{
	int data;
	stack *head_a = NULL;
	stack *last_a = NULL;
	//int objects = argc;
	
	while(argc > 1)
	{
		argv++;
		argc--;
		if(f_atoi(*argv, &data) == 0) 
			return (NULL); //false character
		last_a = list_addlast(data, &last_a, &head_a);
		if(!last_a)
			return (list_free(&head_a), NULL); //malloc fail
	}
	
	

	//tests
	//test_print_from_head(head_a);
	//printf("------------------------\n");
	//test_print_from_last(last_a);
	//list_free(&head_a);

	return head_a;
}