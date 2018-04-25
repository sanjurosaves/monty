#include "monty.h"
/**
 * 
 *
 *
 *
 *
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int count;

	(void)(line_number);
	for (count = 0; *stack != NULL; count++)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	return;
}
