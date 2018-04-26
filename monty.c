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
	unsigned int i, lineno = 0;
	int retd, char_count, cmpresult, numcheck = 3003;
	char instr[ISIZE] = {0}, value[VSIZE] = {0};
	char *buf = NULL;
	size_t buf_size = 0;
	FILE *fs;
	stack_t *stack = NULL;
	long val;

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
		{
			cmpresult = strcmp(instr, "push");
			if (cmpresult == 0)
			{
				printf("L%d: usage: push integer\n", lineno);
				fall(&stack);
				free(buf);
				fclose(fs);
				exit(EXIT_FAILURE);
			}
			if (get_mi_func(instr, lineno, &stack) == -1)
			{
				fall(&stack);
				free(buf);
				fclose(fs);
				exit(EXIT_FAILURE);
			}
		}
		else if (retd == 2)
		{
			for (i = 0; value[i] != '\0'; i++)
			{
				numcheck = isdigit(value[i]);
				if (numcheck == 0)
				{
					printf("L%d: usage: push integer\n", lineno);
					fall(&stack);
					free(buf);
					fclose(fs);
					exit(EXIT_FAILURE);
				}
			}
			val = strtol(value, NULL, 10);
			global = val;
			if (get_mi_func(instr, lineno, &stack) == -1)
			{
				fall(&stack);
				free(buf);
				fclose(fs);
				exit(EXIT_FAILURE);
			}
		}
	}

	malloc_fail(buf);
	free(buf);
	fclose(fs);
	fall(&stack);

	return (0);
}
