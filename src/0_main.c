#include "header.h"
#include <stdio.h>


int main(int argc, char **argv)
{	

	stack *head_a;

	
	argv = split_input(&argc, argv);
	//printf("TEST2\n");
	head_a = createstack(argc, argv);

	sort(head_a, (argc - 1));
	//test_print_from_head(head_a);
	//freeargv(&argv, argc);
	return (1);
}




// int check_input(char *s)
// {
// 	int i;

// 	//if(check_input(argv[1]) == 0)
// 	//	return 0;
// 	i = 0;
// 	while(s[i]) //check for invalid characters
// 	{
// 		if( s[i] > '0' || s[i] < '9' || s[i] == ' ')
// 			i++;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }


// void freeargv(char ***argv, int argc)
// {
// 	while(argc > 0)
// 	{
// 		free((*argv)[argc - 1]);
// 		argc--;
// 	}
// 	free(*argv);
// 	*argv = NULL;
// }
/*
take integers
convert char into integers
*/