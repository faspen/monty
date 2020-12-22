#include "monty.h"

/**
* _add - add the top two items together
* @stack: stack used for adding
* @line_number: line number
*/
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *math;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	math = *stack;

	if (!math->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	math->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(math);
	(*stack)->prev = NULL;
}
