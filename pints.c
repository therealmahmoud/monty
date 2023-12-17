#include "monty.h"

/**
 * pint_s - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pint function is called.
 */

void pint_s(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (argument->stackHead == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_argss();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", argument->stackHead->n);
}
