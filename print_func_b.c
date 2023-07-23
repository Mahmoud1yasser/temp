#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_c - Copy a character into the buffer & print if buffer is full
 * @args: Va_list of all given arguments to _printf
 * @buffer: The buffer being copied to to print
 * @buflen: The current length of the buffer aka number of characters in buffer
 * @bufpos: Current position, or index, inside the buffer
 *
 * Return: Returns number of characters copied to buffer, allows for _printf to
 * return proper number of characters printed
 */
int print_c(va_list args, char buffer[], int *buflen, int *bufpos)
{
	if (*buflen < 1024)
	{
		buffer[*bufpos] = va_arg(args, int);
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
	}
	else
	{
		write_buffer(buffer, buflen, bufpos);
		buffer[*bufpos] = va_arg(args, int);
		*bufpos += 1;
		*buflen += 1;
	}
	return (1);
}
/**
 * print_s - Copy a string into the buffer & print if buffer is full
 * @args: Va_list of all given arguments to _printf
 * @buffer: The buffer being copied to to print
 * @buflen: The current length of the buffer aka number of characters in buffer
 * @bufpos: Current position, or index, inside the buffer
 *
 * Return: Returns number of characters copied to buffer, allows for _printf to
 * return proper number of characters printed
 */
int print_s(va_list args, char buffer[], int *buflen, int *bufpos)
{
	char *s;
	int count, chars;

	count = chars = 0;
	s = va_arg(args, char *);
	if (s == NULL)
	{
		s = "(null)";
	}
	while (s[count] != '\0')
	{
		if (*buflen < 1024)
		{
			buffer[*bufpos] = s[count];
			*bufpos += 1;
			*buflen += 1;
			if (*buflen == 1024)
				write_buffer(buffer, buflen, bufpos);
		}
		else
		{
			write_buffer(buffer, buflen, bufpos);
			buffer[*bufpos] = s[count];
			*bufpos += 1;
			*buflen += 1;
		}

		count++;
		chars++;
	}
	return (chars);
}
