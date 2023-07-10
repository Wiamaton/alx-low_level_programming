#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 *
 * @filename: Pointer to the name of the file.
 * @text_content: Null-terminated string to append.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, app, i;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_WRONLY | O_EXCL | O_APPEND);
	if (file < 0)
		return (-1);

	if (text_content != NULL)
	{
		i = 0;
		while (text_content[i] != '\0')
			i++;

		app = write(file, text_content, i);
		if (app < 0)
		{
			close(file);
			return (-1);
		}
	}

	close(file);
	return (1);
}
