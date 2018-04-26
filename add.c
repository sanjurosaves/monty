#include "monty.h"
/**
 * add - adds data from top two stack elements
 * @stack: pointer to the head of the list
 *@line_number: current line number in main for error handling
 *Return: none/void
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	int length, sum = 0;
        stack_t *temp;

        temp = *stack;
	length = stack_len(*stack, line_number);
	if (length < 2)
	{
		fprintf(stdout,"L%d: can't add, stack too short", line_number);
                exit(EXIT_FAILURE);
	}
	sum += temp->n + temp->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
        return;
}
