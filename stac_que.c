#include "monty.h"

/**
 * stack_s - sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */

void stack_s(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	args->stack = 1;
}


/**
 * queue_s - sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */

void queue_s(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	args->stack = 0;
}
