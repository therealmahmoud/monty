#include "monty.h"

/**
 * init_args - Initializes the argument structure.
 */

void init_args(void)
{
	argument->instruction = malloc(sizeof(instruction_t));
	if (argument->instruction == NULL)
		malloc_fails();

	argument->stackHead = NULL;
	argument->line = NULL;

	argument->n_tokens = 0;
	argument->isComment = 0;
	argument->line_number = 0;
	argument->stack = 1;
	argument->stack_length = 0;
	argument->stream = NULL;
}

/**
 * check_num_of_args - Checks the number of command-line arguments.
 * @argc: The number of command-line arguments.
 */

void check_num_of_args(int argc)
{
	if (argc == 2)
		return;

	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * read_fails - Handles the error when reading a file fails.
 * @fileName: The name of the file that failed to open.
 */

void read_fails(char *fileName)
{
	fprintf(stderr, "Error: Can't open file %s\n", fileName);
	free_argss();
	exit(EXIT_FAILURE);
}


/**
 * malloc_fails - Handles the error when malloc fails to allocate memory.
 */

void malloc_fails(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_argss();
	exit(EXIT_FAILURE);
}
