# ifndef HEADER_H
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

#define PRINT 1


void go_left(stack **head_a, stack **head_b, int *argc, int *argb);
void go_right(stack **head_a, stack **head_b, int *argc, int *argb);
int find_pos_max(stack *head);
int find_shortest_way(stack **head, int argb);

int	push_to_b(stack **head_a, stack **head_b, int argc, int chunksize);
void push_to_a(stack **head_a, stack **head_b, int *argc, int *argb);

//input
char	**split_input(int *argc, char **argv);
char	**f_split(char *s, int *argc);
char	*f_atoi(const char *s, int *data);
char	*check_doubles(stack *head);
char	*check_sorting(stack *head);

//stack/list
stack	*createstack(int argc, char **argv);
stack	*list_newnode(int data);
stack	*list_addlast(int data, stack **last, stack **head);
stack 	*list_getlast(stack *head);

//index ops
void	indexing(stack *head, int argc);
stack	*find_no_index(stack *temp);
int		find_indx_max(stack *head);
int		find_indx_min(stack *head);

int     find_pos_min(stack *head);
void    min_to_top(stack **head_a, int argc);

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
void	rx_left(stack **head, char c);
void	rrx_right(stack **head, char c);

//clean
void	free_exit(char ***argv, int argc, stack *head_a, int success);
void	free_argv(char ***argv, int argc);
void	free_list(stack **head);

//test
void test_print_from_last(stack *last);
void	test_print_from_head(stack *a, stack *b);

#endif