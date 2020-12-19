#include "monty.h"

/**
* _push - add item to stack
* @stack: pointerpointer to double link list
* @line_number: number of lines
*/
void _push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *item;

	item = malloc(sizeof(stack_t));
	if (!item)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	item->n = main_int;

	if (!*stack)
		item->next = NULL;
	else
		item->next = *stack;
	*stack = item;

	if (item->next)
		item->next->prev = item;
}
