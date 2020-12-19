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
	
	node = (*stack)->next;
	*stack = node;
	node = node->prev;
	(*stack)->prev = NULL;
	free(node);
}
