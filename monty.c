#include "monty.h"

int global = 0;

/**
 * main - monty entry point - parses file in arg
 * @argv: command line argument array
 * @argc: count of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	unsigned int lineno = 0;
	int retd, char_count = 0;
	char instr[ISIZE] = {0}, value[VSIZE] = {0};
	char *buf = NULL;
	size_t buf_size = 0;
	FILE *fs;
	stack_t *stack = NULL;

	usage_verify(argc);
	access_verify(argv[1]);

	fs = fopen(argv[1], "r");

	while (1)
	{
		if (buf != NULL)
			free(buf);
		buf = NULL;
		char_count = getline(&buf, &buf_size, fs);
		if (char_count == -1)
			break;
		lineno++;
		retd = vread(buf, "%s %[^\n]%s", instr, value);
		if (retd == 1)
			get_mi_func(instr, lineno, &stack);
		else if (retd == 2)
		{
			global = atoi(value);
			get_mi_func(instr, lineno, &stack);
		}
	}

	malloc_fail(buf);
	free(buf);
	fclose(fs);

	return (0);
}
