#include "header.h"

int make_word(char **split, char *s, int j)
{
	int len;
	int temp;

	len = 0;
	temp = 0;
	while (s[len] && s[len] != ' ')
		len++;
	//printf("%i\n", j);
	split[j] = malloc(sizeof(char) * (len + 1));
    if (!split[j])
        return -1;
	while (temp < len)
	{
		//printf("%c\n",s[temp]);
		split[j][temp] = s[temp];
		temp++;
	}
	split[j][len] = '\0';
	//printf("%i = %s \n", j, split[j]);
	return (len);
}

int count_words(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(s[i])
	{
		if (s[i] != ' ' && (s[i-1] == ' ' || i == 0))
			count++;
		i++;
	}
	return (count);
}

char **f_split(char *s, int *argc)
{
	int i;
	int j;
	char **split;

	i = 0;
	j = 1;
	*argc = count_words(s) + 1; //+1 for programm name
	split = malloc(sizeof(char*) * ((*argc) + 1));
	if(!split)
		return (NULL);
	split[0] = NULL;//index 0 is programm Name, will be skipped
	while(s[i])
	{
		if(s[i] != ' ' && (s[i-1] == ' ' || i == 0))
		{
			i = i + make_word(split, &s[i], j);
			if(!split)
				return(NULL);
			j++;
		}
		i++;
	}
	split[(*argc)] = NULL;
	return(split);
}

//int main()
//{
//	char *s = " Hallo Hey Hhhhey wie gehts dir?";
//	char **split;
//	int argc = 0;
//	int j = 0;

//	split = f_split(s, &argc);
//	printf("%i\n", argc);
	
//	while(j < argc + 1)
//	{
//		printf("%i = %s \n", j, split[j]);
//		j++;
//	}
//}