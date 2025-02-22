#include "header.h"

//free functions
void 	clean_exit(char ***argv, int argc, stack *head_a, int success);
void	list_free(stack **head);

void	clean_exit(char ***argv, int argc, stack *head_a,int success)
{
	if((*argv)[0] == NULL) //input was splitted == argv was allocated
	{
		while(argc >= 0)
		{				
			free((*argv)[argc]);
			argc--;
		}			
		free(*argv);
		*argv = NULL;
	}
	list_free(&head_a);
	if(success == 0)
		{printf("exit success\n");exit(EXIT_SUCCESS);}
	else
		{printf("exit failure\n");exit(EXIT_SUCCESS);}
}

void	list_free(stack **head)
{
	stack *temp;

	temp = *head;
	while(*head)
	{
		temp = (*head)->next;
		//free((*head)->data);
		free(*head);
		*head = temp;
	}
}