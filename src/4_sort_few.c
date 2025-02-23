/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:38:29 by jpaselt           #+#    #+#             */
/*   Updated: 2025/02/20 21:49:15 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//sort few
void	sort_two(stack *head);
stack	*sort_three(stack *head);
stack	*sort_four(stack *head_a, stack **head_b);

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

stack	*sort_four(stack *head_a, stack **head_b)
{
	int pos_min= findmin(head_a);

	if (pos_min == 1)
        swap_sx(head_a, 'a');
    else if (pos_min == 2)
    {
		ra_left(&head_a, 'a');
		ra_left(&head_a, 'a');
	} 
	else if (pos_min == 3)
        rra_right(&head_a, 'a');
	push_px(&head_a, head_b, 'a');
    head_a = sort_three(head_a);// Now sort the top 3
	push_px(head_b, &head_a, 'b');
    
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
     return (head_a);
}
