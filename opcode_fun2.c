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
	if (args->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		close_stream();
		free_tokenz();
		free_argss();
		exit(EXIT_FAILURE);
	}

	tmp1 = args->stackHead;
	tmp2 = tmp1->next;

	tmp2->n = tmp1->n + tmp2->n;
	delete_node();

	args->stack_length -= 1;
}

/**
 * swap_s - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the swap function is called.
 */

void swap_s(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	(void) stack;
	if (args->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_argss();
		exit(EXIT_FAILURE);
	}

	tmp1 = args->stackHead;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	if (tmp1->next)
		tmp1->next->prev = tmp1;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp2->prev = NULL;
	args->stackHead = tmp2;
}

/**
* delete_node - delete node at the head/top
* Return: void
*/

void delete_node(void)
{
	stack_t *tmp;

	tmp = args->stackHead;
	args->stackHead = tmp->next;
	free(tmp);
}
