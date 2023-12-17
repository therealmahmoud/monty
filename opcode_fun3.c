#include "monty.h"

/**
 * div_s - Divides the second top element of the stack by the top element.
 * @stack: Unused pointer to the head of the stack.
 * @line_number: Line number in the file.
 * Description: Exits with EXIT_FAILURE and prints an error message if the
 * stack is too short or if the top element is zero. Otherwise, performs the
 * division and updates the stack length.
 */

void div_s(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	(void) stack;
	if (args->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
				line_number);
		close_stream();
		free_tokenz();
		free_argss();
		exit(EXIT_FAILURE);
	}
	if (args->stackHead->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
				line_number);
		close_stream();
		free_tokenz();
		free_argss();
		exit(EXIT_FAILURE);
	}
	tmp1 = args->stackHead;
	tmp2 = tmp1->next;
	tmp2->n = tmp2->n / tmp1->n;
	delete_node();
	args->stack_length -= 1;
}