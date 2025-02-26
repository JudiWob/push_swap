#include "header.h"

//./pushswap  88 675 2 0 999 -08643 56 78 -456 4 -666 -4 777 -543 9 -23 99 22

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

//printf("index %i\n", head_a->next->data);
// printf("Pos Max %i\n", findmax(head_a));

//TESTING END

	free_list (&head_a);
	printf("exit\n");
	return 0;
}


