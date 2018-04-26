#include "monty.h"
/**
 *stack_len - get length of a doubly linked list
 *@h: pointer to head of linked list
 *Return: number of nodes
 */
int stack_len(stack_t *h, unsigned int line_number)
{
	int count;
        stack_t *temp;
	(void)line_number;
        temp = h;

        for (count = 0; temp != NULL; count++)
                temp = temp->next;

        return count;
}
