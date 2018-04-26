#include "monty.h"
/**
 *
 * swap - swaps data from top two stack elements
 * @stack: pointer to the head of the list
 * @line_number: current line number in main for error handling
 *Return: none/void
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int length, val = 0;
	stack_t *temp;

	temp = *stack;
	length = stack_len(*stack, line_number);
	if (length < 2)
	{
		printf("L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	val = temp->n;
	temp->n = temp->next->n;
	temp->next->n = val;
}
