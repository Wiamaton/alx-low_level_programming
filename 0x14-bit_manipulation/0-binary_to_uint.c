#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec_val = 0;

	if (b == NULL)
		return 0;

	for (; *b; b++)
	{
		if (*b < '0' || *b > '1')
			return 0;
		dec_val = (dec_val * 2) + (*b - '0');
	}

	return dec_val;
}
