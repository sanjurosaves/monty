#include "monty.h"
/**
 * str - prints the string starting at the top of the stack
 *
 * @stack: double pointer to top of stack
 * @line_number: current line number for error handling
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int letter, x, length;

	length = stack_len(*stack, line_number);

	if (!(*stack))
	{
		printf("\n");
		exit(EXIT_FAILURE);
	}
	for (x = 0; x < length; x++)
	{
		letter = (*stack)->n;
		if ((letter < 72) || (letter > 122))
		{
			printf("\n");
			return;
		}
		else
			printf("%c", letter);
		(*stack) = (*stack)->next;
	}
	printf("\n");
}
