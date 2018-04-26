#include "monty.h"
/**
 * sub - subtracts data from top two stack elements
 * @stack: pointer to the head of the list
 *@line_number: current line number in main for error handling
 *Return: none/void
 *
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int length, prod = 0;
	stack_t *temp;

	temp = *stack;
	length = stack_len(*stack, line_number);
	if (length < 2)
	{
		printf("L%u: can't mul, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	prod = (temp->next->n - temp->n);
	pop(stack, line_number);
	(*stack)->n = prod;
}
