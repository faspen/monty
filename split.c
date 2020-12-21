#include "monty.h"

/**
* copy - copy string
* @str: string
* Return: new copy
*/
char *copy(char *str)
{
	int len = 0, values = 0;
	char *paste = NULL;

	if (!str)
		return (NULL);
	while (str[len])
		len++;
	paste = malloc(sizeof(char) * (len + 1));

	while (values <= len)
	{
		paste[values] = str[values];
		values++;
	}
	return (paste);
}

/**
* split - get tokens
* @line: line used
* Return: toks
*/
char **split(char *line)
{
	char *tok, **toks;
	char *str1, *str2;
	int a = 1;
	const char *d = " \t\n";

	str1 = copy(line);
	str2 = copy(line);

	tok = strtok(str1, d);
	while (tok)
	{
		tok = strtok(NULL, d);
		a++;
	}

	toks = malloc(sizeof(char *) * a);

	a = 0;
	toks[a] = strtok(str2, d);

	while (toks[a] && a <= 2)
	{
		toks[a] = strtok(NULL, d);
		a++;
	}
	free(str1);
	return (toks);
}
