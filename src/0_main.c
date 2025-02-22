#include "header.h"
#include <stdio.h>


int main(int argc, char **argv)
{	
	stack *head_a;

	argv = prep_input(&argc, argv);
	head_a = createstack(argc, argv);
	sort(head_a, (argc - 1));
//	test_print_from_head(head_a);

	clean_exit_success(&argv, argc, head_a);

}


