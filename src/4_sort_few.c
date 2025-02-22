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
void	sort_three(stack *head);

void	sort_two(stack *head)
{
	if(head->data > head->next->data)
			swap_one(head, 'a');
	return;
}

// void sort_three(stack *head)
// {
//     if (head->data > head->next->data && head->data > head->next->next->data) // Largest Element at top (645 und 654)
//     {
//         ra_left(head, 'a'); //becomes 456 oder 
//         if (head->data > head->next->data) //546
//             swap_one(head, 'a'); // becomes 456
//     }
//     else if (head->next->data > head->data 
// 	&& head->next->data > head->next->next->data) // Largest Element at in middle (564 und 465)
//     {
//         rra_right(head, 'a'); // becomes 456 oder
//         if (head->data < head->next->next->data) //546
//             swap_one(head, 'a'); // becomes 456
//     }
//     else if (head->data > head->next->data) // Largest Element at bottom (456 und 546)
//     {
//     	swap_one(head, 'a');
//     }
// 	return;
// }

