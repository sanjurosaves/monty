#include "monty.h"
/**
 * push - pushes an element to the stack
 * @line_number: line number
 * @stack: double pointer to top of stack
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	unsigned int n = global;
	stack_t *new;

	(void)(line_number);

	/* create space for new node */
	new = malloc(sizeof(stack_t));
	/*check malloc*/
	if (new == NULL)
		return;

	/*assign members of new node*/
	new->n = n;
	new->next = *stack;
	new->prev = NULL;

	/*previous is different depending on edge case*/
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}

	*stack = new;
}
