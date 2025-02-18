/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_createstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuno <tsuno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:21:27 by jpaselt           #+#    #+#             */
/*   Updated: 2025/02/18 14:08:56 by tsuno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

stack *createstack(int argc, char **argv)
{
	int data;
	stack *head = NULL;
	stack *last = NULL;
	
	while(argc > 1)
	{
		argv++;
		argc--;
		if(f_atoi(*argv, &data) == 0) 
			return (NULL); //false character
		last = list_addlast(data, &last, &head);
		if(!last)
			return (NULL); //malloc fail
	}

	//tests
	test_print_from_head(head);
	printf("------------------------\n");
	test_print_from_last(last);
	//list_free(&head);

	return head;
}