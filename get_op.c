#include "monty.h"

/**
* get_op - check for operation
* @str: given argument
* @stack: stack given
* @line: line
*/
void get_op(char **str, stack_t **stack, int line)
{
	monty_t ops[] = {
		{"push", _push}, {"pall", _pall},
		{"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"pop", _pop},
		{"pint", _pint}, {NULL, NULL}
	};
	int i;

	if (str[0])
	{
		for (i = 0; ops[i].opcode; i++)
		{
			if (!(strcmp(ops[i].opcode, str[0])))
			{
				if (!strcmp(str[0], "push"))
				{
					if (str[1] != NULL && _evaluate(str[1]) == 1)
						main_int = atoi(str[i]);
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", line);
						exit(EXIT_FAILURE);
					}
				}
				ops[i].f(stack, (unsigned int)line);
				break;
			}
		}
	}
	if (!ops[i].f)
	{
		fprintf(stderr, "L%d: unkown instruction %s\n", line, str[0]);
		exit(EXIT_FAILURE);
	}
}
