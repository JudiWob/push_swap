#include "header.h"

//clean input
char	**prep_input(int *argc, char **argv);
char	*f_atoi(const char *s, int *data);
char	*check_doubles(stack *head);
char	*check_sorting(stack *head);

char	**prep_input(int *argc, char **argv)
{
	if (*argc < 2)
	{
		printf("%s", "No arguments\n");
		exit(EXIT_FAILURE);
	}	
	if (*argc == 2)
	{
		argv = f_split(argv[1], argc);	//split argv[1]
		if(!argv)						//exit: malloc failure while f_split
		{
			printf("fail to split\n");
			exit(EXIT_FAILURE);
		}
	}
	return(argv); //argv is split now if argc==2, or nothing happend if argc>2
}

char	*f_atoi(const char *s, int *data)
{
	int i;
	int sign;

	sign = 1;
	*data = 0;
	i = 0;
	while (s[i])
	{
		if(s[i] == '-')
		{
			sign = -1;
			i++;
		}	
		if(s[i] < '0' || s[i] > '9')
		{
			printf("false character\n");
			return (NULL);
		}	
		*data = ((*data) * 10) + (s[i] - 48);
		i++;
	}
	*data = *data * sign;
	return ("ok");
}

char	*check_doubles(stack *head)
{
	stack *temp;

	if(!head || !head->next)
		return NULL;
	temp = head->next;
	while(head->next)
	{
		while(temp)
		{
			if(head->data == temp->data)
				return (printf("Double!\n"), NULL);
			temp = temp->next;
		}
		temp = head->next->next;
		head = head->next;
	}
	return ("ok");
}

char	*check_sorting(stack *head)
{
	stack *temp;

	if(!head || !head->next)
		return (NULL);
	
	temp = head;
	while(temp->next)
	{
		if(temp->data > temp->next->data)
		{
			return (NULL);
		}	
		temp = temp->next;
	}
	return (printf("SORTED!\n"),"sorted");
}