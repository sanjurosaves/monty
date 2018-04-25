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
	int n = line_number;

	(void)(n);
	(void)(count);
	for (count = 0; stack != NULL; count++)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	return;
}
