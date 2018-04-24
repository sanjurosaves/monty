#include "monty.h"
int get_mi_func(char *mi, int n)
{
	instruction_t valid_mis[] = {
                {"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	(void)(mi);
	(void)(n);
	(void)(valid_mis);

	return (0);
}
