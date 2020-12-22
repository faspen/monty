#include "monty.h"

/**
* get_op - check for operation
* @str: given argument
* @line: line
* Return: appropriate function
*/
void (*get_op(char **str, unsigned int line))(stack_t **, unsigned int)
{/* below is the array of opcodes */
	instruction_t ops[] = {
		{"push", _push}, {"pall", _pall},
		{"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"pop", _pop},
		{"pint", _pint}, {"sub", _sub},
		{"mul", _mul}, {NULL, NULL}
	};

	unsigned int i = 0;
	char hold = 0; /* this char will reduce line space */

	while (ops[i].opcode)
	{/* ! is anohter way of saying if the strings are the same */
		if (!(strcmp(ops[i].opcode, str[0])))
		{
			hold = (!strcmp(ops[i].opcode, "push"));
			if (hold && (str[1] == NULL || (!(_evaluate(str[1])))))
			{/* if character after push is null or not a number */
				fprintf(stderr, "L%d: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
			else if (!(strcmp(ops[i].opcode, "push")))
				main_int = atoi(str[1]);

			free(str);
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unkown instruction %s\n", line, str[0]);

	free(str);
	exit(EXIT_FAILURE);
}
