#include "monty.h"

/**
* free_stack_s - free the nodes in a stack list
* @head: first node of a dlistint link
* Return: void
*/
void free_stack_s(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
	{
		free_stack_s(head->next);
	}

	free(head);
}
