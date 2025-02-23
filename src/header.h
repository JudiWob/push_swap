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
char	**f_split(char *s, int *argc);
int		f_atoi(const char *s, int *data);
char	*check_doubles(stack *head_a);

//stack
stack	*createstack(int argc, char **argv);
stack	*list_newnode(int data);
stack	*list_addlast(int data, stack **last, stack **head);
stack 	*list_getlast(stack *head);
int		findmax(stack *head);
int		findmin(stack *head);

//sort
void	sort(stack **head_a, int argc);
void	sort_two(stack *head_a);
stack 	*sort_three(stack *head_a);
stack 	*sort_four(stack *head_a, stack **head_b);
void	push_px(stack **head_take, stack **head_put, char c);

//operations
void	swap_sx(stack *head, char x);
void	swap_ss(stack *head_a, stack *head_b);
void	ra_left(stack **head, char c);
void	rra_right(stack **head, char c);


//clean
void	free_exit(char ***argv, int argc, stack *head_a, int success);
void	free_argv(char ***argv, int argc);
void	free_list(stack **head);

//test
void test_print_from_last(stack *last);
void test_print_from_head(stack *head);
//int check_input(char *s);

#endif