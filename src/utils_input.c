/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:23:30 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/23 18:48:37 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**split_input(int *argc, char **argv);
char	*f_atoi(const char *s, long *data);
char	*check_doubles(t_stack *head);
char	*check_sorting(t_stack *head);
char	*check_int_size(long data);

char	**split_input(int *argc, char **argv)
{
	if (*argc < 2)
	{
		ft_printf("ERROR\n");
		exit(EXIT_FAILURE);
	}
	if (*argc == 2)
	{
		argv = f_split(argv[1], argc);
		if (!argv)
		{
			exit(EXIT_FAILURE);
		}
	}
	return (argv);
}

char	*f_atoi(const char *s, long *data)
{
	int	i;
	int	sign;

	sign = 1;
	*data = 0;
	i = 0;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			//ft_printf("ERROR1\n");
			return (NULL);
		}
		*data = ((*data) * 10) + (s[i] - 48);
		i++;
	}
	if (!check_int_size(*data))
		return (NULL);
	*data = *data * sign;
	return ("ok");
}

char	*check_int_size(long data)
{
	if (data > INT_MAX || data < INT_MIN)
	{
		return (NULL);
	}
	else
		return ("int size ok");
}

char	*check_doubles(t_stack *head)
{
	t_stack	*temp;

	if (!head || !head->next)
		return (NULL);
	temp = head->next;
	while (head->next)
	{
		while (temp)
		{
			if (head->data == temp->data)
				return (NULL);
			temp = temp->next;
		}
		temp = head->next->next;
		head = head->next;
	}
	return ("ok");
}

char	*check_sorting(t_stack *head)
{
	t_stack	*temp;

	if (!head || !head->next)
		return (NULL);
	temp = head;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
		{
			return (NULL);
		}
		temp = temp->next;
	}
	ft_printf("OK\n");
	return ("sorted");
}
