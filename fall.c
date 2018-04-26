#include "monty.h"
/**
 * fall - free stack
 * @stack: double pointer to stack
 * Return: void
 */
void fall(stack_t **stack)
{
	stack_t *tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
