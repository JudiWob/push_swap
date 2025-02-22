#ifndef HEADER_H
# define HEADER_H


#include "../libft/libft.h"
#include <stdio.h>

typedef struct stack{
	int 			data;
	struct stack	*next;
	struct stack	*prev;
} stack;


#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

//input
char	**prep_input(int *argc, char **argv);
int		f_atoi(const char *s, int *data);
char	**f_split(char *s, int *argc);
void	clean_exit_fail(char ***argv, int argc, stack *head_a);
void	clean_exit_success(char ***argv, int argc, stack *head_a);
char	*check_doubles(stack *head_a);

//stack
stack	*createstack(int argc, char **argv);
stack	*list_newnode(int data);
stack	*list_addlast(int data, stack **last, stack **head);
void	list_free(stack **head);

//sort
void	sort(stack *head_a, int argc);
void	sort_two(stack *head_a);
//void sort_three(stack *head_a);
void	swap_one(stack *head, char x);

//clean
void	freeargv(char ***argv, int argc);

//test
void test_print_from_last(stack *last);
void test_print_from_head(stack *head);
//int check_input(char *s);

#endif