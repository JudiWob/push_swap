#ifndef HEADER_H
# define HEADER_H

#include "../libft/libft.h"
#include "limits.h"
#include "stdio.h"

typedef struct stack{
	int 			data;
	int				index;
	struct stack	*next;
	struct stack	*prev;
} stack;

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define PRINT 0

//input
char	**prep_input(int *argc, char **argv);
char	**f_split(char *s, int *argc);
char	*f_atoi(const char *s, int *data);
char	*check_doubles(stack *head);
char	*check_sorting(stack *head);

//stack/list
stack	*createstack(int argc, char **argv);
stack	*list_newnode(int data);
stack	*list_addlast(int data, stack **last, stack **head);
stack 	*list_getlast(stack *head);
void	indexing(stack *head, int argc);
stack	*indexing_min_node(stack *temp);

//sort
void	sort(stack **head_a, int argc);
void	sort_two(stack *head_a);
stack 	*sort_three(stack *head_a);
stack 	*sort_four(stack *head_a);
stack 	*sort_five(stack *head_a);

//operations
void	swap_sx(stack *head, char x);
void	swap_ss(stack *head_a, stack *head_b);
void	push_px(stack **head_take, stack **head_put, char c);
void	ra_left(stack **head, char c);
void	rra_right(stack **head, char c);
int		findmax(stack *head);
int		findmin(stack *head);
int		find_indx_middle(stack *head, int arg);
void	few_mintotop(stack **head_a);
void	split_median_a(stack **head_a, stack **head_b, int *argc, int *argb);
void	split_median_b(stack **head_a, stack **head_b, int *argc, int *argb);
//void	push_back_three(stack **head_a, stack **head_b, int *argc, int *argb);
//void	sort_while_moving(stack **head_a, stack **head_b, int *argc, int *argb);
void	chunking(stack **head_a, stack **head_b, int *argc, int *argb, int chunksize);
void	chunk_sorting(stack **head_a, stack **head_b, int chunksize);

//clean
void	free_exit(char ***argv, int argc, stack *head_a, int success);
void	free_argv(char ***argv, int argc);
void	free_list(stack **head);

//test
void test_print_from_last(stack *last);
void	test_print_from_head(stack *a, stack *b);

#endif