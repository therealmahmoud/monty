#include "monty.h"

/**
 * tokenize_s - Tokenizes the input line.
 */

void tokenize_s(void)
{
	int i = 0;
	char *delims = " \n", *token = NULL, *linecpy = NULL;

	linecpy = malloc(sizeof(char) * (strlen(args->line) + 1));
	strcpy(linecpy, args->line);
	args->n_tokens = 0;
	token = strtok(linecpy, delims);
	while (token)
	{
		args->n_tokens += 1;
		token = strtok(NULL, delims);
	}

	args->line_strs = malloc(sizeof(char *) *
			(args->n_tokens + 1));
	strcpy(linecpy, args->line);
	token = strtok(linecpy, delims);
	while (token)
	{
		args->line_strs[i] = malloc(sizeof(char) *
				(strlen(token) + 1));
		if (args->line_strs[i] == NULL)
			malloc_fails();
		strcpy(args->line_strs[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	args->line_strs[i] = NULL;
	free(linecpy);
}
