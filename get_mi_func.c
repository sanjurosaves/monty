#include "monty.h"
int get_mi_func(char *mi, unsigned int n)
{
	stack_t *stack = NULL;
	unsigned int i = 0;
	instruction_t valid_mis[] = {
                {"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (valid_mis[i].opcode != NULL)
	{
		if (strcmp(mi, valid_mis[i].opcode) == 0)
		    valid_mis[i].f(&stack, n);
		i++;
	}

	return (0);
}
