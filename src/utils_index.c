#include "header.h"

//index ops
void	indexing(stack *head, int argc);
stack	*find_no_index(stack *temp);
int		find_indx_middle(stack *head, int arg);
int		find_indx_max(stack *head, int range);
int		find_indx_min(stack *head, int range);


void indexing(stack *head, int argc)
{
    stack *temp;
    stack *min_node;
    int index;

    index = 1;
    while (index <= argc)
    {
        temp = head;
        min_node = find_no_index(temp); 
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
// printf("index %i\n", head->index);
	return ;
}

stack	*find_no_index(stack *temp)
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


int find_indx_max(stack *head, int range)
{
    stack *temp;

    int max;
	int n;

    temp = head;
    n = 0;
	while(n < range && temp)
	{
		if(temp->index > max)
			max = temp->index;
		temp = temp->next;
		n++;
	}
    return (max);

}

int find_indx_min(stack *head, int range)
{
    stack *temp;

    int min;
	int n;

    temp = head;
    n = 0;
	while(n < range && temp)
	{
		if(temp->index < min)
			min = temp->index;
		temp = temp->next;
		n++;
	}
    return (min);
}

int find_indx_middle(stack *head, int range)
{
	int min;
	int max;
	int mitte;

	min = find_indx_min(head, range);
	max = find_indx_max(head, range);

printf("min %i\n", min);
printf("max %i\n", max);
	mitte = ((max - min) / 2) + min;
	if((min + max) % 2 != 0)
        mitte++;
printf("mitte %i\n", mitte);
	return (mitte);
}