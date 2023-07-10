#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - Allocates a buffer with a size of 1024 bytes.
 * @file: The name of the file for which the buffer is created.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Failed to allocate memory for buffer in file %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Failed to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect, exit with code 97.
 *              If the source file does not exist or cannot
 *              be read, exit with code 98.
 *              If the destination file cannot be created
 *              or written to, exit with code 99.
 *              If the files cannot be closed, exit with code 100.
 */
int main(int argc, char *argv[])
{
	int source_file, destination_file, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	source_file = open(argv[1], O_RDONLY);
	read_bytes = read(source_file, buffer, 1024);
	destination_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_file == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Failed to read from source file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_bytes = write(destination_file, buffer, read_bytes);
		if (destination_file == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Failed to write to destination file %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_bytes = read(source_file, buffer, 1024);
		destination_file = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(buffer);
	close_file(source_file);
	close_file(destination_file);

	return (0);
}
