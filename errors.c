#include "monty.h"
/**
 * usage_verify - print usage error to standard input
 *@argc: number of arguments passed to function
 *Return: none/void
 */
void usage_verify(int argc)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * access_verify - print access error to standard input
 *@arg: file on which access is attempted
 *Return: none/void
 */
void access_verify(char *arg)
{
	int fd = open(arg, O_RDONLY);

	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", arg);
		exit(EXIT_FAILURE);
	}

	close(fd);
}
/**
 * malloc_fail - print malloc error to standard input
 *@buf: buffer malloced for
 *Return: none/void
 */
void malloc_fail(char *buf)
{
	if (buf == NULL)
	{
		free(buf);
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * unknown_mi - prints error when unknown monty instruction is found
 * Return: 0
 */
int unknown_mi(void)
{

/**
 * if (instructions in file are not in header)
 *
 * {printf("L%d: unknown instruction %s", <line number> <opcode>);
 * exit(EXIT FAILURE);
 * compare first word of each line in program against header file, first
 * one that doesn't match retur\ns error counter for line number?
 */
	return (0);

}
