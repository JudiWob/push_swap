#include "header.h"

char **split_input(int *argc, char **argv)
{
	
	//printf("in inputsplit\n");
	if (*argc < 2)
	{
		printf("%s", "No arguments\n");
		exit(EXIT_FAILURE);
	}	
	if (*argc == 2)
	{
		argv = f_split(argv[1], argc);
	
		//printf("after split argv0: %s\n", argv[0]);
		if(!argv)
		{
			printf("fail to split\n");
			exit(EXIT_FAILURE);
		}
	}
	//printf("argv1: %s\n", (argv)[1]);
	//printf("end of input split TEST\n");
	return(argv);
}