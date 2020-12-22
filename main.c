#include "monty.h"

/**
* main - main file of monty interpreter
* @argc: argument number
* @argv: arguments
* Return: success or fail
*/
int main(int argc, char *argv[])
{
	char *file = argv[1];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	inspect(file);
	exit(EXIT_SUCCESS);
}
