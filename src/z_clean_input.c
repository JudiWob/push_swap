#include "header.h"

//clean input
char	**prep_input(int *argc, char **argv);
int		f_atoi(const char *s, int *data);
char	*check_doubles(stack *head_a);

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

int	f_atoi(const char *s, int *data)
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
			return (-1);
		}	
		*data = ((*data) * 10) + (s[i] - 48);
		i++;
	}
	*data = *data * sign;
	return (1);
}

char	*check_doubles(stack *head_a)
{
	stack *temp;
	stack *go;

	if(!head_a || !head_a->next)
		return NULL;
	temp = head_a;
	go = temp->next;
	while(temp->next)
	{
//		printf("temp %i\n", temp->data);
		while(go)
		{
//			printf("go %i\n", go->data);
			if(temp->data == go->data)
				return (printf("Double!\n"), NULL);
			go = go->next;
		}
		go = temp->next->next;
		temp = temp->next;
	}
	return ("ok");
}

