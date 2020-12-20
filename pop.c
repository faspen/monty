#include "monty.h"

/**
* _pop - remove top element of stack
* @stack: stack to modify
* @line_number: used in error
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
	}

	node = (*stack)->next; /* node comes after stack */
	*stack = node; /* stack and node are now the same */
	node = node->prev; /* move stack behind */
	(*stack)->prev = NULL; /* stack->prev kills node */
	free(node); /* if you love something set it free */
}
