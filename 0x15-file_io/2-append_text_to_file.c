#include "main.h"
#include <stdio.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist or the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file;
	int result = -1;

	if (filename == NULL)
		return (-1);

	file = fopen(filename, "a");
	if (file == NULL)
		return (-1);

	if (text_content != NULL)
	{
		fputs(text_content, file);
		result = (1);
	}

	fclose(file);

	return (result);
}
