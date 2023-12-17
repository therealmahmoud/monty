#include "monty.h"

/**
 * free_all_arguments - Frees all allocated memory for arguments.
 */

void free_all_arguments(void)
{
	close_stream();
	free_tokenz();
	free_argss();
}

/**
 * free_tokenz - Frees the allocated memory for tokens.
 */

void free_tokenz(void)
{
	int i = 0;

	if (args->line_strs)
	{
		while (args->line_strs[i])
		{
			free(args->line_strs[i]);
			i++;
		}
		free(args->line_strs);
	}
}

/**
 * free_stack_Head - Frees the memory allocated for the stackHead and
 * sets it to NULL.
 */

void free_stackHead(void)
{
	if (args->stackHead)
		free_stack_s(args->stackHead);

	args->stackHead = NULL;
}

/**
 * close_stream - Closes the file stream and sets it to NULL.
 */

void close_stream(void)
{
	if (args->stream)
	{
		fclose(args->stream);
		args->stream = NULL;
	}
}

/**
 * free_arg - Frees the memory allocated for the args
 * structure and its members.
 */

void free_argss(void)
{
	if (args == NULL)
		return;

	if (args->instruction)
	{
		free(args->instruction);
		args->instruction = NULL;
	}

	free_stackHead();

	if (args->line)
	{
		free(args->line);
		args->line = NULL;
	}

	free(args);
}
