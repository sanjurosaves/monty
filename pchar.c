#include "monty.h"
/**
 * pchar - print character at top of stack
 *
 * @stack: double pointer to top of stack
 * @line_number: current line number for error handling
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((atoi((*stack)->n < 65)) || (atoi((*stack)->n > 122)))
	{

		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
