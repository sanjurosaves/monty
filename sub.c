#include "monty.h"
/**
 * sub - subtracts data from top two stack elements
 * @stack: pointer to the head of the list
 *@line_number: current line number in main for error handling
 *Return: none/void
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int length, diff = 0;
	stack_t *temp;

	temp = *stack;
	length = stack_len(*stack, line_number);
	if (length < 2)
	{
		exit(EXIT_FAILURE);
	}
	diff = (temp->next->n - temp->n);
	pop(stack, line_number);
	(*stack)->n = diff;
}
