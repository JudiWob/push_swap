/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort_few.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuno <tsuno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:38:29 by jpaselt           #+#    #+#             */
/*   Updated: 2025/02/26 16:05:52 by tsuno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//sort few
void	sort_two(stack *head);
stack	*sort_three(stack *head);
stack	*sort_four(stack *head_a);
stack	*sort_five(stack *head_a);
void    min_to_top(stack **head_a);

void	sort_two(stack *head)
{
	if(head->data > head->next->data)
			swap_sx(head, 'a');
	return;
}

stack *sort_three(stack *head)
{
    if (head->data > head->next->data && head->data > head->next->next->data) // Largest Element at top (645 und 654)
    {
        ra_left(&head, 'a'); //becomes 456 oder 
        if (head->data > head->next->data) //546
            swap_sx(head, 'a'); // becomes 456
    }
    else if (head->data < head->next->data
	&& head->next->data > head->next->next->data) // Largest Element at in middle (564 und 465)
    {
        rra_right(&head, 'a'); // becomes 456 oder
        if (head->data > head->next->data) //546
            swap_sx(head, 'a'); // becomes 456
    }
    else if (head->data > head->next->data) // Largest Element at bottom (456 und 546)
    {
    	swap_sx(head, 'a');
    }
	return (head);
}

stack	*sort_four(stack *head_a)
{
	stack *head_b;

    head_b = NULL;
	min_to_top(&head_a);

	push_px(&head_a, &head_b, 'a');
    head_a = sort_three(head_a);// Now sort the top 3
	push_px(&head_b, &head_a, 'b');
    return (head_a);
}

stack	*sort_five(stack *head_a)
{
	stack *head_b;

    head_b = NULL;
    min_to_top(&head_a);
	push_px(&head_a, &head_b, 'a');
    min_to_top(&head_a);
    push_px(&head_a, &head_b, 'a');
    head_a = sort_three(head_a);// Now sort the top 3
	push_px(&head_b, &head_a, 'b');
    push_px(&head_b, &head_a, 'b');
    return (head_a);
}

void min_to_top(stack **head_a)
{
    int indx_min;

    printf("test\n");
    indx_min = find_pos_min(*head_a);
//printf("Minimum %i\n", indx_min);
    if (indx_min == 2)
    {
        swap_sx(*head_a, 'a');
    }
    else if (indx_min == 3)
    {
		ra_left(head_a, 'a');
		ra_left(head_a, 'a');
	} 
    else if (indx_min > 3)
    {
        rra_right(head_a, 'a');
        if(indx_min == 3)
            rra_right(head_a, 'a');
    }
    return;
}

// printf("A:");
// test_print_from_last(list_getlast(head_a));
// printf("A:");
// test_print_from_head(head_a);
// if(!*head_b)
// {
// 	printf("Stack b is empty\n");
// 	return head_a;
// }	
// printf("B:");
// test_print_from_last(list_getlast(*head_b));
// printf("B:");
// test_print_from_head(*head_b);