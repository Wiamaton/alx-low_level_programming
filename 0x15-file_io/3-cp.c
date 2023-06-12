#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(FILE *file);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file.
 * @file: The file to be closed.
 */
void close_file(FILE *file)
{
	if (fclose(file) != 0)
	{
		fprintf(stderr, "Error: Can't close file\n");
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	FILE *from, *to;
	size_t r, w;
	char *buffer;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = fopen(argv[1], "r");
	if (from == NULL)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	to = fopen(argv[2], "w");
	if (to == NULL)
	{
		fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		exit(99);
	}

	while ((r = fread(buffer, sizeof(char), 1024, from)) > 0)
	{
		w = fwrite(buffer, sizeof(char), r, to);
		if (w != r)
		{
			fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
	}

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
