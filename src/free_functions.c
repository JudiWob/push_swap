#include "header.h""

void clean_exit(char ***argv, int argc, stack *head_a);
void freeargv(char ***argv, int argc);
void list_free(stack **head);

void clean_exit(char ***argv, int argc, stack *head_a)
{
	*argv = *argv - argc + 1;
	if((*argv)[0] == NULL)
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
	//	DELETE LATER
	//	if(!head_a && !(*argv))
	//	printf("all free\n");
	//
	//	return;
	exit (EXIT_FAILURE);
}


void freeargv(char ***argv, int argc)
{
	while(argc > 0)
	{
		free((*argv)[argc - 1]);
		argc--;
	}
	free(*argv);
	*argv = NULL;
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