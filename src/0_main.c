#include "header.h"

//
int	main(int argc, char **argv);

int main(int argc, char **argv)
{	
	stack *head_a;
	argv = prep_input(&argc, argv);
	head_a = createstack(argc, argv);
	indexing(head_a, argc);
	sort(&head_a, (argc - 1));

//TESTING

//printf("MAIN TESTS\n");
// test_print_from_last(list_getlast(head_a));
//test_print_from_head(head_a);
// printf("Pos Max %i\n", findmax(head_a));

//TESTING END

//	free_list (head_a);
	free_exit(&argv, argc, head_a, 0);
	return 0;
}


