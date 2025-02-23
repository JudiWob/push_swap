#include "header.h"
#include <stdio.h>


int main(int argc, char **argv)
{	
	stack *head_a;
	argv = prep_input(&argc, argv);
	head_a = createstack(argc, argv);
	sort(&head_a, (argc - 1));

//TESTING
// printf("MAIN TESTS\n");
// stack *last;
// last = list_getlast(head_a);
// //test_print_from_last(last);
test_print_from_head(head_a);

// int pos;
// pos = findmax(head_a);
// printf("Pos Max %i\n", pos);

//TESTING

	//free  head_a, 0);

	return 0;
}


