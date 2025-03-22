/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort_few.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:38:29 by jpaselt           #+#    #+#             */
/*   Updated: 2025/03/22 14:59:36 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//sort few
void	sort_two(stack *head);
stack	*sort_three(stack *head);
stack	*sort_four(stack *head_a);
stack	*sort_five(stack *head_a);


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
        rx_left(&head, 'a'); //becomes 456 oder 
        if (head->data > head->next->data) //546
            swap_sx(head, 'a'); // becomes 456
    }
    else if (head->data < head->next->data
	&& head->next->data > head->next->next->data) // Largest Element at in middle (564 und 465)
    {
        rrx_right(&head, 'a'); // becomes 456 oder
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
	
	min_to_top(&head_a, 4);
	push_px(&head_a, &head_b, 'a');
    head_a = sort_three(head_a);// Now sort the top 3
	push_px(&head_b, &head_a, 'b');
    return (head_a);
}

stack	*sort_five(stack *head_a)
{
	stack *head_b;

    head_b = NULL;
    min_to_top(&head_a, 5);
	push_px(&head_a, &head_b, 'a');
    min_to_top(&head_a, 4);
    push_px(&head_a, &head_b, 'a');
    head_a = sort_three(head_a);// Now sort the top 3
	push_px(&head_b, &head_a, 'b');
    push_px(&head_b, &head_a, 'b');
    return (head_a);
}
