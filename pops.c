#include "monty.h"

/**
 * pop_s - Removes the top element from the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pop function is called.
 */

void pop_s(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (argument->stackHead == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		close_stream();
		free_tokenz();
		free_argss();
		exit(EXIT_FAILURE);
	}

	delete_node();
	argument->stack_length -= 1;
}
