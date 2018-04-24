#include "monty.h"
int main(int argc, char *argv[])
{
	int fd, char_count;
	char *buf;
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
	char_count = getline(&buf, &buf_size, fs);
	if (char_count == -1)
	{
		free(buf);
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* tokenize */
	/* check first word against list of opfuncs */
	/* return error if matching function pointer not found */
	printf("%s\n", buf);
	free(buf);

	fclose(fs);

	return (0);
}
