#include "header.h"

char **split_input(int *argc, char **argv)
{
	if (*argc < 2)
	{
		printf("%s", "No arguments\n");
		exit(EXIT_FAILURE);
	}	
	if (*argc == 2)
	{
		argv = f_split(argv[1], argc);
		if(!argv)
		{
			printf("fail to split\n");
			exit(EXIT_FAILURE);
		}
	}
	return(argv);
}