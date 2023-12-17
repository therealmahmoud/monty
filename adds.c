#include "monty.h"

/**
 * add_s - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the add function is called.
 */

void add_s(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	(void) stack;
	if (argument->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		close_stream();
		free_tokenz();
		free_argss();
		exit(EXIT_FAILURE);
	}

	tmp1 = argument->stackHead;
	tmp2 = tmp1->next;

	tmp2->n = tmp1->n + tmp2->n;
	delete_node();

	argument->stack_length -= 1;
}
