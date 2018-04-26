#include "monty.h"
/**
 * pop - delete head node
 * @stack: pointer to the head of the list
 * @line_number: current line number in main for error handling
 * Return: none
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *temp2;

	temp = *stack;
	temp2 = temp->next;
	free(temp);
	*stack = temp2;
}
