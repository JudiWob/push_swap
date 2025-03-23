/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:39:46 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/23 18:36:06 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../ft_printf/ft_printf.h"
# include "limits.h"
# include "stdlib.h"

typedef struct stack
{
	long			data;
	int				index;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

# define PRINT 1

//input
char	**split_input(int *argc, char **argv);
char	**f_split(char *s, int *argc);
char	*f_atoi(const char *s, long *data);
char	*check_doubles(t_stack *head);
char	*check_sorting(t_stack *head);
char	*check_int(long data);

//t_stack/list
t_stack	*createt_stack(int argc, char **argv);
t_stack	*list_newnode(long data);
t_stack	*list_addlast(long data, t_stack **last, t_stack **head);
t_stack	*list_getlast(t_stack *head);

//indexing
void	indexing(t_stack *head, int argc);
t_stack	*find_no_index(t_stack *temp);
int		find_indx_max(t_stack *head);
int		find_indx_min(t_stack *head);

//sort general 
void	sort(t_stack **head_a, int argc);
void	sort_two(t_stack *head_a);
t_stack	*sort_three(t_stack *head_a);
t_stack	*sort_four(t_stack *head_a);
t_stack	*sort_five(t_stack *head_a);

//sort ops
void	go_left(t_stack **head_a, t_stack **head_b, int *argc, int *argb);
void	go_right(t_stack **head_a, t_stack **head_b, int *argc, int *argb);
int		find_pos_max(t_stack *head);
int		find_shortest_way(t_stack **head, int argb);
int		push_to_b(t_stack **head_a, t_stack **head_b, int argc, int chunksize);
void	push_to_a(t_stack **head_a, t_stack **head_b, int *argc, int *argb);
int		find_pos_min(t_stack *head);
void	min_to_top(t_stack **head_a, int argc);
//void	loop(t_stack **head_a, t_stack **head_b, int *argc, int chunksize);

//operations
void	swap_sx(t_stack *head, char x);
void	swap_ss(t_stack *head_a, t_stack *head_b);
void	push_px(t_stack **head_take, t_stack **head_put, char c);
void	rx_left(t_stack **head, char c);
void	rrx_right(t_stack **head, char c);

//clean exit
void	free_exit(char ***argv, int argc, t_stack *head_a, int success);
void	free_argv(char ***argv, int argc);
void	free_list(t_stack **head);

//test
void	test_print_from_last(t_stack *last);
void	test_print_from_head(t_stack *a, t_stack *b);

#endif