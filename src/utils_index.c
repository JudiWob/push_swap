#include "header.h"

//index ops
void	indexing(stack *head, int argc);
stack	*find_no_index(stack *temp);
int		find_indx_middle(stack *head, int arg);
int		find_indx_max(stack *head, int range);
int		find_indx_min(stack *head, int range);


void indexing(stack *head, int argc)
{
    //stack *temp;
    stack *min_node;
    int index;

    index = 1;
   // temp = head;
    while (index <= argc)
    {
        
        //printf("Looking for node with index %d\n", index);
        min_node = find_no_index(head);
        if (min_node)
        {
           // printf("Found node with data %d, assigning index %d\n", min_node->data, index);
            min_node->index = index;
            index++;
        }
        else
        {
          //  printf("No unindexed node found, breaking\n");
            break;
        }
    }

    // Print all nodes after indexing
    stack *temp = head;
    while (temp)
    {
     //   printf("Node data: %d, index: %d\n", temp->data, temp->index);
        temp = temp->next;
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
	max = temp->index;
	while(n < range && temp)
	{
//printf(" index %i\n", temp->index);
//printf("\n  temp data %i\n\n", temp->data);
		if(temp->index > max)
		{
			max = temp->index;
//printf("\n  temp data %i\n\n", temp->data);
		}	
//		printf("\n data temp %i\n\n", temp->data);
		temp = temp->next;
		n++;
	}
//printf("\n MAX%i\n", max);
    return (max);

}

int find_indx_min(stack *head, int range)
{
    stack *temp;

    int min;
	int n;

    temp = head;
    n = 0;
	min = temp->index;
	while(n < range && temp)
	{
		if(temp->index < min)
			min = temp->index;
		temp = temp->next;
		n++;
	}
//printf("\n\n%i\n\n", min);
    return (min);
}

int find_indx_middle(stack *head, int range)
{
	int min;
	int max;
	int mitte;

	min = find_indx_min(head, range);
	max = find_indx_max(head, range);

//printf("min %i\n", min);
//printf("max %i\n", max);
	mitte = ((max - min) / 2) + min;
	if((max) % 2 != 0)
        mitte++;
//printf("mitte %i\n", mitte);
//printf("head index %i", (head)->index);
	return (mitte);
}

	// int n;
	// stack *temp;


	// temp = head;
	// while(temp)
	// {
	// 	mitte = mitte + temp->data / n;
	// 	temp = temp->next;
	// 	n++,
	// }