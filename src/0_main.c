#include "header.h"

//./pushswap  88 675 2 0 999 -08643 56 78 -456 4 -666 -4 777 -543 9 -23 99 22
//./pushswap 1 -762 3 -1 2 5 999 -1111 63  -6574  30  2222 65 -222 75645 -74334 758 963 41 18 432 564 
// ./pushswap 8829 -7652 7645 -8843 3929 -6878 7280 -2923 -12 2307 -4253 7488 4474 621 -7656 -4801 7960 1684 -4049 2803 873 -8808 219 9566 -6914 7527 3578 -262 3371 4711 5075 -2723 -4417 2141 6921 -6745 1665 8406 1961 9129 -1940 -5747 5429 -492 -1969 -2184 -9926 -9209 7432 -4551 -7595 -2302 -6013 581 7199 4096 3241 4131 1988 6981 -4740 -4707 3417 -1609 -9693 9256 -9367 2231 9372 -9543 -6830 -1472 1293 8972 -4675 -4614 1270 -433 5277 1534 2138 1027 5065 2908 -6226 176 5599 8503 -837 4448 -6207 2124 5066 -7877 5796 3173 -2504 -151 -3202 1771 
int main(int argc, char **argv)
{	
	stack *head_a;
	argv = prep_input(&argc, argv);
	head_a = createstack(argc, argv);
	indexing(head_a, argc);
// printf("argc %i\n",  argc);
	sort(&head_a, (argc - 1));

//TESTING

//printf("MAIN TESTS\n");
// test_print_from_last(list_getlast(head_a));

//printf("index %i\n", head_a->next->data);
// printf("Pos Max %i\n", findmax(head_a));

//TESTING END

	free_list (&head_a);
	//printf("exit\n");
	return 0;
}


