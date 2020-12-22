#include "monty.h"

/**
* split - get tokens
* @line: line used
* Return: toks
*/
char **split(char *line)
{
	char *tok, **toks;
	int a = 0;

	toks = malloc(sizeof(char *) * 3);

	if (!toks)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line, " '\n'");

	if (!tok)
	{
		free(toks);
		return (NULL);
	}

	while (tok && a < 2)
	{
		toks[a] = tok;
		tok = strtok(NULL, " '\n'");
		a++;
	}
	toks[a] = NULL;
	return (toks);
}
