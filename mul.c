#include "monty.h"
/**
 * mul - multiplies data from top two stack elements
 * @stack: pointer to the head of the list
 * @line_number: current line number in main for error handling
 * Return: none/void
 *
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int length, prod = 0;

	length = stack_len(*stack, line_number);

	if (length < 2)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	prod = ((*stack)->n * (*stack)->next->n);
	pop(stack, line_number);
	(*stack)->n = prod;
}
