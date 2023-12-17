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

/**
 * mod_s - Computes the modulus of the second top element by the top element.
 * @stack: Unused pointer to the head of the stack.
 * @line_number: Line number in the file.
 * Description: Exits with EXIT_FAILURE and prints an error message if the
 * stack is too short or if division by zero is attempted. Otherwise,
 * performs the modulus operation and updates the stack length.
 */

void mod_s(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	(void) stack;
	if (args->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
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
	tmp2->n = tmp2->n % tmp1->n;
	delete_node();
	args->stack_length -= 1;
}

/**
 * pchar_s - Prints the ASCII character of the top element of the stack.
 * @stack: Unused pointer to the head of the stack.
 * @line_number: Line number in the file.
 * Description: Exits with EXIT_FAILURE and prints an error message if the
 * stack is empty or if the value is out of range. Otherwise, prints the
 * ASCII character of the top element.
 */

void pchar_s(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (args->stack_length == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
				line_number);
		close_stream();
		free_tokenz();
		free_argss();
		exit(EXIT_FAILURE);
	}
	if (args->stackHead->n < 0 || args->stackHead->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_number);
		close_stream();
		free_tokenz();
		free_argss();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", args->stackHead->n);
}

/**
 * pstr_s - Prints the ASCII characters from the stack
 * @stack: A pointer to the stack
 * @line_number: The line number in the script
 */

void pstr_s(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int i = args->stack_length;

	(void) stack;
	(void) line_number;

	tmp = args->stackHead;
	while (i > 0 && tmp != NULL && tmp->n != 0)
	{
		if ((tmp->n >= 32 && tmp->n <= 126))
		{
			printf("%c", tmp->n);
		}
		else
		{
			break;
		}
		tmp = tmp->next;
		i--;
	}
	printf("\n");
}
