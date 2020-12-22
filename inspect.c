#include "monty.h"

/**
* inspect - read file passed
* @argstring: argument
*/
void inspect(char *argstring)
{
	stack_t *stack = NULL;
	FILE *file;
	int count = 0;
	char *line = NULL, **argues;
	size_t buf = 0;
	void (*f)(stack_t **stack, unsigned int line_number);

	file = fopen(argstring, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argstring);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &buf, file) != -1)
	{
		count++;
		argues = split(line); /* tokenize */
		if (!argues)
			continue;
		else
			f = get_op(argues, count);

		if (f != NULL)
			f(&stack, count);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(file);
			myfree(&stack);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	myfree(&stack);
	free(line);
}
