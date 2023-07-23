#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_char - Copy a character & print buffer if full
 * @appindex: Va_list of printf
 * @buffer: The buffer being copied to to print
 * @len: The current length of the buffer aka number of characters in buffer
 * @pos: Current position, or index, inside the buffer
 *
 * Return: Returns number of characters copied to buffer, allows for _printf to
 * return proper number of characters printed
 */
int print_char(va_list appindex, char buffer[], int *len, int *pos)
{
	if (*len < 1024)
	{
		buffer[*pos] = va_arg(appindex, int);
		*pos += 1;
		*len += 1;
		if (*len == 1024)
			write_buf(buffer, len, pos);
	}
	else
	{
		write_buf(buffer, len, pos);
		buffer[*pos] = va_arg(appindex, int);
		*pos += 1;
		*len += 1;
	}
	return (1);
}

