#include "monty.h"

/**
* inspect - read file passed
* @argstring: argument
* @stack: stack passed
*/
void inspect(char *argstring, stack_t **stack)
{
	FILE *file = fopen(argstring, "r");
	char *line = NULL, **argues;
	int count;
	size_t buf = 0;

	if (file)
	{
		while (getline(&line, &buf, file) != -1)
		{
			count++;
			if (line[0] == '\n')
				continue;
			argues = split(line);
			get_op(argues, stack, count);
		}
		free(line);
		fclose(file);
	}
	else
	{
		fprintf(stderr, "Error, Can't open file %s\n", argstring);
		exit(EXIT_FAILURE);
	}
}
