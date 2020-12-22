#include "monty.h"

/**
* myfree - frees double linked list
* @stack: list to free
*/
void myfree(stack_t **stack)
{
	stack_t *node;

	if (!*stack)
		return;
	while (*stack != NULL)
	{
		node = (*stack)->next;
		free(*stack);
		if (!node)
			return;
		node->prev = NULL;
		*stack = node;
	}
	free(stack);
}
