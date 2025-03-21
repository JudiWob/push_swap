#include "header.h"

//
void push_to_a(stack **head_a, stack **head_b, int *argc, int *argb);
void go_left_max(stack **head_a, stack **head_b, int *argc, int *argb);
void go_right_max(stack **head_a, stack **head_b, int *argc, int *argb);
int find_pos_max(stack *head);
int find_shortest_way(stack **head, int argb);

void push_to_a(stack **head_a, stack **head_b, int *argc, int *argb)
{
    int direction;

    if(!*head_b)
        return;
	direction = find_shortest_way(head_b, *argb);
    if(direction == 1)
        go_left_max(head_a, head_b, argc, argb);
    else 
        go_right_max(head_a, head_b, argc, argb);
	return;
}

void go_right_max(stack **head_a, stack **head_b, int *argc, int *argb)
{
    int max;

    max = find_indx_max(*head_b);

    while(*head_b) 
	{
        if ((*head_b)->index == max - 1)
        {
            push_px(head_b, head_a, 'a'); 
            (*argc)++;
            (*argb)--;
        }
        if ((*head_b)->index == max)
        {
            push_px(head_b, head_a, 'a');
            (*argc)++;
			(*argb)--;
            if ((*head_a) && ((*head_a)->next) && (*head_a)->index > (*head_a)->next->index)
            swap_sx(*head_a, 'a');
            break;
        }    
        if (*head_b)
            rra_right(head_b, 'b');
    }
 //printf("head b index %i\n", (*head_b)->index);
}
    


void go_left_max(stack **head_a, stack **head_b, int *argc, int *argb)
{
    int max;

    max = find_indx_max(*head_b);
    while(*head_b) 
	{
        if ((*head_b)->index == max - 1)
        {
            push_px(head_b, head_a, 'a'); 
            (*argc)++;
            (*argb)--;
        }
        if ((*head_b)->index == max)
        {
            push_px(head_b, head_a, 'a');
            (*argc)++;
			(*argb)--;
            if ((*head_a) && ((*head_a)->next) && (*head_a)->index > (*head_a)->next->index)
                swap_sx(*head_a, 'a');
            break;
        }    
        if (*head_b)
            ra_left(head_b, 'b');
    }
    return;
}

int find_shortest_way(stack **head, int argb)
{
    int pos_max;
    int direction;

    pos_max = find_pos_max(*head);

    direction = 1;

    if(pos_max > argb/2)
        direction = 0;

    return (direction);
}

int find_pos_max(stack *head)
{
   stack   *max;
   int     n;
   int     pos;

   max = head;
   n = 1;
   pos = 1;
   while(head)
   {
       if(max->data < head->data)
       {
           max = head;
           pos = n;
       }    
       head = head->next;
       n++;
   }
//printf("Pos %i\n", pos);
//printf("Max %i\n", max->data);
   return (pos);
}