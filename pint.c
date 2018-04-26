#include "monty.h"
/**
 * pall - print all values on the stack
 *
 * @stack: double pointer to top of stack
 * @line_number: current line number for error handling
 *
 * Return: void/none
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if(!(*stack))
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
	return;
}
