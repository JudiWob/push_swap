/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_free_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:24:18 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/30 14:54:56 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_exit(char ***argv, int argc, t_stack *head_a, int success);
void	free_argv(char ***argv, int argc);
void	free_list(t_stack **head);

void	free_exit(char ***argv, int argc, t_stack *head_a, int success)
{
	if ((*argv)[0] == NULL)
	{
		while (argc >= 0)
		{
			free((*argv)[argc]);
			argc--;
		}
		free(*argv);
		*argv = NULL;
	}
	free_list(&head_a);
	if (success == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(EXIT_SUCCESS);
	}
}

void	free_argv(char ***argv, int argc)
{
	if ((*argv)[0] == NULL)
	{
		while (argc >= 0)
		{
			free((*argv)[argc]);
			argc--;
		}
		free(*argv);
		*argv = NULL;
	}
	return ;
}

void	free_list(t_stack **head)
{
	t_stack	*temp;

	temp = *head;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}
