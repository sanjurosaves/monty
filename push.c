#include "monty.h"
/**
 *
 *
 *
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	unsigned int n = line_number;
	stack_t *last = *stack;
        stack_t *new;
/*create space for new node*/
	new = malloc(sizeof(stack_t));
/*check malloc*/
	if (new == NULL)
		return;
/*assign members of new node*/
	new->n = n;
	new->next = NULL;
/*previous is different depending on edge case*/
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
/*move to end of linked list*/
	while (last->next != NULL)
		last = last->next;

	new->prev = last;
	last->next = new;

	return;
}
