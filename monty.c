#include "monty.h"
int main(int argc char *argv[])
{
	int fd;

	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

/** if (instructions in file are not in header)*/
/**{
/**printf("L%d: unknown instruction %s", <line number> <opcode>);*/
/**exit(EXIT FAILURE);
compare first word of each line in program against header file, first one that doesn't match returns error counter for line number?
/**}
}
