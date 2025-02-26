/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_createstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuno <tsuno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:21:27 by jpaselt           #+#    #+#             */
/*   Updated: 2025/02/26 15:51:07 by tsuno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//create stack and indexing
stack	*createstack(int argc, char **argv);
stack	*indexing_min_node(stack *temp);
void	indexing(stack *head, int argc);

stack	*createstack(int argc, char **argv)
{
	int 	data;
	stack 	*head_a;
	stack 	*last_a;
	char 	**original_argv;

	head_a = NULL;
	original_argv = argv;
	while(argc > 1) //build list
	{
		argv++;
		argc--;
		if(!f_atoi(*argv, &data)) 						//convert char *argv to int data
			free_exit(&original_argv, argc, head_a, -1); 	//exit: false character
		last_a = list_addlast(data, &last_a, &head_a); 		//make node and store data
//last_a = NULL;
		if(!last_a)
			free_exit(&original_argv, argc, head_a, -1); 	//exit: malloc fail making node
	}
	if(!check_doubles(head_a))
		free_exit(&original_argv, argc, head_a, -1);		//exit:doubles
//	if(check_sorting(head_a))								
//		free_exit(&original_argv, argc, head_a, 1);			//exit:already sorted
test_print_from_head(head_a, NULL);
	return (free_argv(&original_argv, argc), head_a);
}

void indexing(stack *head, int argc)
{
    stack *temp;
    stack *min_node;
    int index;

    index = 1;
    while (index <= argc)
    {
        temp = head;
        min_node = indexing_min_node(temp); 
    	if (min_node)
        {
			min_node->index = index;
            index++;
        }
		else
			break;
    }
// printf("INDEX 2: %i\n", head->index);
// printf("INDEX 1: %i\n", head->next->index);
// printf("INDEX 7: %i\n", head->next->next->index);
// printf("INDEX 4: %i\n", head->next->next->next->index);
	printf("index %i\n", head->index);
	return ;
}

stack	*indexing_min_node(stack *temp)
{
	int min;
	stack *min_node;

	min_node = NULL;
	min = INT_MAX;
	while (temp)
    {
		if (temp->data < min && temp->index == 0)
        {
			min = temp->data;
            min_node = temp;
        }
        temp = temp->next;
 }
	return (min_node);
} 

