#include "monty.h"

/**
* split - get tokens
* @line: line used
* Return: toks
*/
char **split(char *line)
{
	char *tok, **toks;
	unsigned int i = 0;

	toks = malloc(sizeof(char *) * 3);

	if (!toks)
	{
		fprintf(stderr, "Error: malloc failer\n");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line, " '\n'");

	if (!tok)
	{
		free(toks);
		return (NULL);
	}

	while (tok && i < 2)
	{
		toks[i] = tok;
		tok = strtok(NULL, " '\n'");
		i++;
	}
	toks[i] = NULL;
	return (toks);
}
