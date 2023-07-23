#include "main.h"
/**
 * print_str - Copy a string into the buffer &print it
 * @appendix: Va_list arguments _printf
 * @buffer: The buffer being copied to to print
 * @len: length of the buffer
 * @pos: Current position for the buffer
 *
 * Return: Returns number of characters copied to buffer
 */
int print_str(va_list appendix, char buffer[], int *len, int *pos)
{
	char *s;
	int count, chars;

	count = chars = 0;
	s = va_arg(appendix, char *);
	if (s == NULL)
	{
		s = "(null)";
	}
	while (s[count] != '\0')
	{
		if (*len < 1024)
		{
			buffer[*pos] = s[count];
			*pos += 1;
			*len += 1;
			if (*len == 1024)
				write_buf(buffer, len, pos);
		}
		else
		{
			write_buf(buffer, len, pos);
			buffer[*pos] = s[count];
			*pos += 1;
			*len += 1;
		}
		chars++;
		count++;
	}
	return (chars);
}
