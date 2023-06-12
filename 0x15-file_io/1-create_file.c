#include "main.h"
#include <stdio.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	FILE *file;
	int result = -1;
	size_t len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len]; len++)
			;
	}

	file = fopen(filename, "w");
	if (file == NULL)
		return (-1);

	if (fwrite(text_content, sizeof(char), len, file) == len)
		result = 1;

	fclose(file);

	return (result);
}
