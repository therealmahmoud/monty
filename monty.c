#include "monty.h"

args_t *args = NULL;

/**
 * main - Entry point
 * @argc: The number of command-line argss.
 * @argv: A pointer to an array of strings containing
 * the command-line argss.
 * Description: print alphabets in lowercase using the putchar
 *
 * Return: returns 0 (Success)
 */
int main(int argc, char **argv)
{
	ssize_t lines_read = 0;
	size_t n = 0;

	check_num_of_args(argc);

	args = malloc(sizeof(args_t));
	if (args == NULL)
		malloc_fails();

	init_args();
	set_stream(argv[1]);

	while ((lines_read = getline(&args->line, &n, args->stream)) != -1)
	{
		args->line_number += 1;
		tokenize_s();
		set_Instructions();
		run_Instructions();
		free_tokenz();
	}

	close_stream();
	free_argss();

	return (0);
}
