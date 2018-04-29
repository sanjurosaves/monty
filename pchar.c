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
	int letter = (*stack)->n;

	if (!(*stack))
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((letter < 65) || (letter > 122))
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	(void)line_number;
	printf("%c\n", letter);
}
