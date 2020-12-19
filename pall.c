#include "monty.h"
/**
* _pall - print everything in the stack top to bottom
* @stack: stack to print
* @line_number: irrelevant
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *printing = *stack;

	if (!*stack)
		exit(EXIT_FAILURE)
	while (printing)
	{
		fprintf(stdout, "%d\n", printing->n);
		printing = printing->next;
	}
}
