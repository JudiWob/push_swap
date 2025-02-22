#include "header.h"

//free functions
void 	clean_exit_fail(char ***argv, int argc, stack *head_a);
void 	freeargv(char ***argv, int argc);
void	list_free(stack **head);

void clean_exit_fail(char ***argv, int argc, stack *head_a)
{
	if((*argv)[0] == NULL) //input was splitted == argv was allocated
	{
		//*argv = *argv - argc + 1; //go back to argv[]
		while(argc >= 0)
		{				
			free((*argv)[argc]);
			argc--;
		}			
		free(*argv);
		*argv = NULL;
	}
	list_free(&head_a);
	printf("Exit Fail\n");
	exit (EXIT_FAILURE);
}

void clean_exit_success(char ***argv, int argc, stack *head_a)
{
	if((*argv)[0] == NULL) //input was splitted == argv was allocated
	{
		while(argc > 0)
		{
			free((*argv)[argc - 1]);
			argc--;
		}
		free(*argv);
		*argv = NULL;
	}
	list_free(&head_a);
	printf("Exit Success\n");
	exit (EXIT_SUCCESS);
}

void list_free(stack **head)
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