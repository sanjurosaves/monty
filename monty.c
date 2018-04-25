#include "monty.h"

int global = 0;

int vread(const char *buffer, char *fmt, ...)
{
	int rc;
	va_list arg_ptr;
	va_start(arg_ptr, fmt);
	rc = vsscanf(buffer, fmt, arg_ptr);
	va_end(arg_ptr);
	return(rc);
}

int main(int argc, char *argv[])
{
	unsigned int lineno = 0;
	int fd, retd, char_count = 0;
	char instr[ISIZE] = {0};
	char value[VSIZE] = {0};
	char *buf = NULL;
	size_t buf_size = 0;
	FILE* fs;

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
	close(fd);

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

		/* tokenize */
		retd = vread(buf, "%s %[^\n]%s", instr, value);
		if (retd == 1)
			printf("%d: %s\n", lineno, instr);
		else if (retd == 2)
		{
			printf("%d: %s %d\n", lineno, instr, atoi(value));
			global = atoi(value);
			printf("Global: %d\n", global);
		}

                get_mi_func(instr, lineno);

		/* return error if matching function pointer not found */
		/* printf("%s\n", buf); */
	}

	if (buf == NULL)
	{
		free(buf);
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	free(buf);

	fclose(fs);

	return (0);
}
