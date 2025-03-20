#include "header.h"

//sort utils
void    min_to_top(stack **head_a, int argc);
int     find_pos_min(stack *head);
void    check_first_two(stack **head_a, stack **head_b);
//int     find_pos_index(stack *head, int min_index);
//int     find_pos_max(stack *head);

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
		ra_left(head_a, 'a');
		ra_left(head_a, 'a');
	} 
    else if (pos_min >= 4)
    {
        rra_right(head_a, 'a');
        if(pos_min == 4 && argc == 5)
            rra_right(head_a, 'a');
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


#include "header.h"




void check_first_two(stack **head_a, stack **head_b) 
{
//printf("check first two\n");
 //test_print_from_head(*head_a, *head_b);
	
	if(!(*head_b) || !(*head_b)->next || !(*head_a) || !(*head_a)->next)
		return;

	//while ((*head_b)->index < (list_getlast(*head_b))->index) //useful if median_a was efficient
     //  rra_right(head_b, 'b');
	//if ((*head_b)->index < (*head_b)->next->index && (*head_a)->index < (*head_a)->next->index)
		swap_ss(*head_a, *head_b);
	//else if ((*head_a)->index > (*head_a)->next->index)
		//swap_sx(*head_a, 'a');
	if ((*head_b)->index < (*head_b)->next->index)
    	swap_sx(*head_b, 'b');	
//printf("after check first two\n");
//test_print_from_head(*head_a, *head_b);
}