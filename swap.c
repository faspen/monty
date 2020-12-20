#include "monty.h"

/**
* get_len - get stack length
* @stack: stack to look at
* Return: length
*/
int get_len(stack_t **stack)
{
	int len = 0;

	while (*stack)
	{
		len++;
		*stack = (*stack)->next;
	}
	return (len);
}

/**
* _swap - swap top two items
* @stack: stack used
* @line_number: number of lines
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int len;

	len = get_len(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = (*stack)->next; /* node is after stack */
	(*stack)->prev = node; /* node is now behind stack */
	(*stack)->next = node->next;
	node->prev = NULL; /* node is first */
	node->next = *stack; /* stack comes after node */
	*stack = node;
}
