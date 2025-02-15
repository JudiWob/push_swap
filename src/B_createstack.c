/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_createstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:21:27 by jpaselt           #+#    #+#             */
/*   Updated: 2025/02/15 21:24:23 by jpaselt          ###   ########.fr       */
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
		data = f_atoi(*argv);
		last = list_addlast(data, &last, &head);
		if(!last)
			return (NULL);
	}

	//tests
	test_print_from_head(head);
	printf("------------------------\n");
	test_print_from_last(last);
	list_free(&head);

	return head;
}