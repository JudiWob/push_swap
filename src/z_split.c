/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:54:45 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/23 16:54:49 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// f_split
char		**f_split(char *s, int *argc);
static int	count_words(char *s);
static int	make_word(char **split, char *s, int j, int *i);
static void	freesplit(char **split, int j);

char	**f_split(char *s, int *argc)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 1;
	*argc = count_words(s) + 1;
	split = malloc(sizeof(char *) * ((*argc) + 1));
	if (!split)
		return (NULL);
	split[0] = NULL;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i - 1] == ' ' || i == 0))
		{
			if (make_word(split, &s[i], j, &i) == 0)
				return (NULL);
			j++;
		}
		else
			i++;
	}
	return (split[(*argc)] = NULL, split);
}

static int	make_word(char **split, char *s, int j, int *i)
{
	int	len;
	int	temp;

	len = 0;
	temp = 0;
	while (s[len] && s[len] != ' ')
		len++;
	split[j] = malloc(sizeof(char) * (len + 1));
	if (!split[j])
		return (freesplit(split, j), 0);
	while (temp < len)
	{
		split[j][temp] = s[temp];
		temp++;
	}
	split[j][len] = '\0';
	*i = *i + len;
	return (len);
}

static int	count_words(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i - 1] == ' ' || i == 0))
			count++;
		i++;
	}
	return (count);
}

void	freesplit(char **split, int j)
{
	while (j >= 0)
	{
		free(split[j]);
		j--;
	}
	free(split);
	split = NULL;
}
