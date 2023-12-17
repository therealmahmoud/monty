#include "monty.h"
#include <fcntl.h>

/**
 * run_Instruction - Runs the instruction specified by the args.
 */

void run_Instructions(void)
{
	stack_t *stack = NULL;

	if (args->n_tokens == 0 || args->isComment)
		return;

	args->instruction->f(&stack, args->line_number);
}

/**
 * invalid_instructions - Handles an unknown instruction error.
 */

void invalid_instructions(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			args->line_number, args->line_strs[0]);
	close_stream();
	free_tokenz();
	free_argss();
	exit(EXIT_FAILURE);
}

/**
 * set_stream - Sets the stream for reading from the specified file.
 * @fileName: Name of the file to open and set as the stream.
 */

void set_stream(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		read_fails(fileName);

	args->stream = fdopen(fd, "r");
	if (args->stream == NULL)
	{
		close(fd);
		read_fails(fileName);
	}
}

/**
 * set_Instructions - Sets the instruction based on the first token
 * in the input line.
 */

void set_Instructions(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push_s}, {"pop", &pop_s},
		{"pint", &pint_s}, {"swap", &swap_s},
		{"nop", &nop_s}, {"add", &add_s},
		{"pall", &pall_s},
		{NULL, NULL}
	};

	if (args->n_tokens == 0) /* no instructions */
		return;


	for (; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, args->line_strs[0])
				== 0)
		{
			args->instruction->opcode = instructions[i].opcode;
			args->instruction->f = instructions[i].f;
			return;
		}
	}

	invalid_instructions();
}

/**
 * is_number_s - Checks if a string represents a valid integer number.
 * @str: The string to check.
 * Return: 1 if the string is a valid number, 0 otherwise.
 */

int is_number_s(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}
