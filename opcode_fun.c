#include "monty.h"

/**
 * push_s - Pushes an integer onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the push function is called.
 */

void push_s(stack_t **stack, unsigned int line_number)
{
	if (args->n_tokens <= 1 || !(is_number_s(args->line_strs[1])))
	{
		free_argss();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_fails();
	(*stack)->next = (*stack)->prev = NULL;

	(*stack)->n = (int) atoi(args->line_strs[1]);

	if (args->stackHead == NULL)
	{
		args->stackHead = *stack;
	}
	else
	{
		if (args->stack)
		{
			(*stack)->next = args->stackHead;
			args->stackHead->prev = *stack;
			args->stackHead = *stack;
		}
		else
		{
			stack_t *tmp = args->stackHead;

			while (tmp->next)
				tmp = tmp->next;
			tmp->next = *stack;
			(*stack)->prev = tmp;
		}
	}
	args->stack_length += 1;
}

/**
 * pall_s - Prints all the elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pall function is called.
 */

void pall_s(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (args->stackHead == NULL)
		return;

	(void) line_number;
	(void) stack;

	tmp = args->stackHead;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


/**
 * pop_s - Removes the top element from the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pop function is called.
 */

void pop_s(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (args->stackHead == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		close_stream();
		free_tokenz();
		free_argss();
		exit(EXIT_FAILURE);
	}

	delete_node();
	args->stack_length -= 1;
}

/**
 * pint_s - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pint function is called.
 */

void pint_s(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (args->stackHead == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_argss();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", args->stackHead->n);
}

/**
 * nop_s - ...
 * @stack: Pointer to the stack.
 * @line_number: Line number where the nop function is called.
 */

void nop_s(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
