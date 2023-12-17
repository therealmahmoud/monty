#include "monty.h"

/**
 * rotr_s - Rotates the stack to the bottom.
 * @stack: Unused pointer to the stack.
 * @line_number: Unused line number in the script.
 */

void rotr_s(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void) line_number;
	(void) stack;
	if (args->stackHead == NULL || args->stackHead->next == NULL)
	{
		return;
	}
		tmp = args->stackHead;
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->prev->next = NULL;
		tmp->next = args->stackHead;
		tmp->prev = NULL;
		args->stackHead->prev = tmp;
		args->stackHead = tmp;
}
