#include "main.h"
#include <unistd.h>

int _putchar(char c)
{
	ssize_t num_written = write(STDOUT_FILENO, &c, 1);
	if (num_written == -1) {
		// Handle error here if desired
		return -1;
	}
	return 1;
}

