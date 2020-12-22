#include "monty.h"

/**
* get_op - check for operation
* @str: given argument
* @line: line
* Return: appropriate function
*/
void (*get_op(char **str, unsigned int line))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", _push}, {"pall", _pall},
		{"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"pop", _pop},
		{"pint", _pint}, {NULL, NULL}
	};
	unsigned int i = 0;
	char ch = 0;

	while (ops[i].opcode)
	{
		if ((strcmp(ops[i].opcode, str[0])) == 0)
		{
			ch = (strcmp(ops[i].opcode, "push") == 0);
			if (ch && (str[1] == NULL || (!(_evaluate(str[1])))))
			{
				free(str);
				return (NULL);
			}
			else if ((strcmp(ops[i].opcode, "push") == 0))
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
