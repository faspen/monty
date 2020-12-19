#include "monty.h"

/**
* _pint - print the stack's top value
* @stack: stack used
* @line_number: line number
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *topnode = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", topnode->n);
}
