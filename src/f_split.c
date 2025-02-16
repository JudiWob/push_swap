#include "header.h"

int make_word(int i, char **split, char *s)
{
	int index;
	int s_len;

	s_len = 0;
	index = i;
	while (s[index] && s[index + 1] != ' ')
	{

	}
}

int count_words(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(s[i])
	{
		if (s[i] == ' ' && s[i+1] != ' ')
			count++;
		i++;
	}
	return (count);
}

char **f_split(char *s, int *argc)
{
	int i;
	int j;
	int count;
	char **split;

	i = 0;
	j = 0;
	
	while(s[i]) //check for invalid characters
	{
		if( s[i] > '0' || s[i] < '9' || s[i] == ' ')
			i++;
		else
			return (NULL);
	}

	count = count_words(s);
	split = malloc(sizeof(char*) * count + 1);
	if(!split)
		return (NULL);
	while(s[i])
	{
		if(s[i] != ' ' && (s[i-1] == ' ' || i == 0))
		{
			i = make_word(i, split, &s[i])
		}
	}
	
}