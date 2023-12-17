#include "monty.h"

/**
 * init_args - Initializes the args structure.
 */

void init_args(void)
{
	args->instruction = malloc(sizeof(instruction_t));
	if (args->instruction == NULL)
		malloc_fails();

	args->stackHead = NULL;
	args->line = NULL;

	args->n_tokens = 0;
	args->isComment = 0;
	args->line_number = 0;
	args->stack = 1;
	args->stack_length = 0;
	args->stream = NULL;
}

/**
 * check_num_of_args - Checks the number of command-line args.
 * @argc: The number of command-line args.
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
