#include "monty.h"

/**
* myfree - frees double linked list
* @stack: list to free
*/
void myfree(stack_t **stack)
{
	stack_t *node = *stack;

	if (!node)
		return;
	while (node->next != NULL)
	{
		node = node->next;
		free(node->prev);
	}
	free(node);
}
