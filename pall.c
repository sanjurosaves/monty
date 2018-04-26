#include "monty.h"
/**
 * pall - print stack
 * @line_number: line number
 * @stack: double pointer to stack
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int count;
	stack_t *tmp;

	(void)(line_number);

	tmp = *stack;

	for (count = 0; *stack != NULL; count++)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}

	*stack = tmp;
}
