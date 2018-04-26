#include "monty.h"

/**
 * get_mi_func - gets monty instruction function
 * @stack: double pointer to stack
 * @n: line number
 * @mi: instruction word
 * Return: 0 upon success
 */
int get_mi_func(char *mi, unsigned int n, stack_t **stack)
{
	int cmpresult;
	unsigned int i = 0, flag = 0;
	instruction_t valid_mis[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"pop", pop},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
	};

	while (valid_mis[i].opcode != NULL)
	{
		cmpresult = strcmp(mi, valid_mis[i].opcode);
		if (cmpresult == 0)
		{
			flag = 1;
			valid_mis[i].f(&*stack, n);
		}
		i++;
	}

	if (flag == 0)
	{
		printf("L%d: unknown instruction %s\n", n, mi);
		exit(EXIT_FAILURE);
	}

	return (0);
}
