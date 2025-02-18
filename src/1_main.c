#include "header.h"
#include <stdio.h>

int main(int argc, char **argv)
{	
	if (argc < 2)
	{
		printf("%s", "No arguments");
		return 0;
	}

	if (argc == 2)
	{
		if(check_input(argv[1]) == 0)
			return 0;
		argv = f_split(argv[1], &argc);
	}

	if(!createstack(argc, argv))
		return (printf("fail createstack\n"), -1);
	
	return (1);
}

int check_input(char *s)
{
	int i;

	i = 0;
	while(s[i]) //check for invalid characters
	{
		if( s[i] > '0' || s[i] < '9' || s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}
/*
take integers
convert char into integers
*/