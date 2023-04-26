#include <stdio.h>

/**
 * print_binary - Prints the binary representation of an unsigned integer.
 *
 * @num: The unsigned integer to convert to binary.
 *
 * Return: void.
 */
void print_binary(unsigned int num)
{
	int i, j;

	for (i = sizeof(unsigned int) * 8 - 1; i >= 0; --i)
	{
		j = (num >> i) & 1;
		putchar(j ? '1' : '0');
	}
}
