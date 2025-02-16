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
		argv = f_split(argv[1], &argc);
	}

	if(!createstack(argc, argv))
		return (printf("fail createstack"), -1);
	
	return (1);
}
/*
take integers
convert char into integers
*/