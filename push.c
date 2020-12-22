#include "monty.h"
int main_int;
/**
* _push - add item to stack
* @stack: pointerpointer to double link list
* @line_number: number of lines
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *item;
	(void)line_number;

	item = malloc(sizeof(stack_t));

	if (!item) /* check if malloc failed */
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	item->n = main_int;

	item->next = *stack;
	item->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = item;

	*stack = item;
}
