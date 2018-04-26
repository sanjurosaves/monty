#include "monty.h"
int get_mi_func(char *mi, unsigned int n, stack_t **stack)
{
	unsigned int i = 0;
	instruction_t valid_mis[] = {
                {"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"pop", pop},
		{NULL, NULL}
	};

	while (valid_mis[i].opcode != NULL)
	{
		if (strcmp(mi, valid_mis[i].opcode) == 0)
		    valid_mis[i].f(&*stack, n);
		i++;
	}

	return (0);
}
