#include "header.h"

//sort utils
void    min_to_top(stack **head_a, int argc);
int     find_pos_min(stack *head);

void min_to_top(stack **head_a, int argc)
{
    int pos_min;

    pos_min = find_pos_min(*head_a);

    if (pos_min == 2)
    {
        swap_sx(*head_a, 'a');
    }
    else if (pos_min == 3)
    {
		rx_left(head_a, 'a');
		rx_left(head_a, 'a');
	} 
    else if (pos_min >= 4)
    {
        rrx_right(head_a, 'a');
        if(pos_min == 4 && argc == 5)
            rrx_right(head_a, 'a');
    }
    //printf("after mintop");
    //test_print_from_head(*head_a, NULL);
    return;
}

int find_pos_min(stack *head)
{
    stack   *min;
    int     n;
    int     pos;

    min = head;
    n = 1;
    pos = 1;
    while(head)
    {
        if(min->data > head->data)
        {
            min = head;
            pos = n;
        }    
        head = head->next;
        n++;
    }
// printf("Pos %i\n", pos);
// printf("Max %i\n", max->data);
    return (pos);
}
