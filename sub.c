#include "monty.h"

/**
* _sub - subtract the top two items
* @stack: stack used for adding
* @line_number: line number
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *math;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	math = *stack;

	if (!math->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	math->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(math);
	(*stack)->prev = NULL;
}
