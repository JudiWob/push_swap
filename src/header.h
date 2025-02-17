#include "../libft/libft.h"
#include <stdio.h>

typedef struct stack{
	int 			data;
	struct stack	*next;
	struct stack	*prev;
} stack;


//input
int f_atoi(const char *s, int *data);
char **f_split(char *s, int *argc);

//stack
stack *createstack(int argc, char **argv);
stack *list_newnode(int data);
stack *list_addlast(int data, stack **last, stack **head);
void list_free(stack **head);

//test
void test_print_from_last(stack *last);
void test_print_from_head(stack *head);
int check_input(char *s);
