#include "monty.h"

/**
* main - main file of monty interpreter
* @argc: argument number
* @argv: arguments
* Return: success or fail
*/
int main(int argc, char *argv[])
{
	stack_t **stack;

	stack = malloc(sizeof(stack_t));
	*stack = NULL;

	if (argc >= 2 && argc <= 3)
		inspect(argv[1], stack);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		myfree(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}
	myfree(stack);
	free(stack);
	return (0);
}
