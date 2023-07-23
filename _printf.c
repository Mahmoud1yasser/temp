#include "main.h"
/**
* clone_2_buf - Copies to the buffer
* @formatter: to be copyied over
* @buffer: Buffer to copy to
* @ptr_blen: Pointer to the length of the buffer
* @ptr_bpos: Pointer to the position in the buffer
*
* Return: Number of characters copied to buffer
*/
int clone_2_buf(char formatter, char buffer[],
		     int *ptr_blen, int *ptr_bpos)
{
	int chars;

	chars = 0;
	buffer[*ptr_bpos] = formatter;
	*ptr_bpos += 1;
	*ptr_blen += 1;
	if (*ptr_blen == 1024)
	{
		write_buf(buffer, ptr_blen, ptr_bpos);
	}
	chars++;
	return (chars);
}


/**
* check_con - Checks formatter character to see if
* it's a conversion specifier
* @formatter: The format character being checked
* @con: Struct holding conversion specifiers & function pointers to
* @appropriate functions for corresponding conversion specifier
* @buffer: Buffer needed to copy to when calling function
* @ptrblen: Pointer to the length of the buffer
* @ptrbpos: Pointer to the position within the buffer
* @ap: va_list holding all given arguments to _printf function
*
* Return: Return the number of characters copied to buffer if a
* function is called, 0 if no function is called
*/
int check_con(char formatter, char_funcs con[], char buffer[],
		     int *ptrblen, int *ptrbpos, va_list ap)
{
	int j, chars;

	chars = 0;
	for (j = 0; j < 5; j++)
	{
		if (formatter == *con[j].c)
		{
			chars += con[j].f(ap, buffer, ptrblen,
						  ptrbpos);
			return (chars);
		}
	}
	return (0);
}
/**
 * formatp - function search in string format for the %.
 * @format: string which contains list of % indentifier.
 * @to_be_printed: arguments in printf
 * @buffer: memory for printing
 * @ptrblen: pointer to buffer length
 * @ptrbpos: pointer to current
 * position in buffer
 * @con: pointer to format func.
 * Return: position of identifier.
 */
int formatp(const char *format,
		va_list to_be_printed, char buffer[],
		int *ptrblen, int *ptrbpos,
		char_funcs con[])
{
	int pos, temp, chars;

	chars = 0;
	for (pos = 0; format[pos] != '\0' && format != NULL; pos++)
	{
		if (format[pos] == '%')
		{
			pos++;
			temp = check_con(format[pos],
					con, buffer, ptrblen,
					ptrbpos, to_be_printed);
			if (temp == 0)
			{
				chars += clone_2_buf(format[pos],
						buffer, ptrblen, ptrbpos);
			}
			chars += temp;
		}
		else
		{
			chars += clone_2_buf(format[pos],
					buffer, ptrblen, ptrbpos);
		}
	}
	return (chars);
}

/**
 * _printf - clone for original printf
 * @format: pointer for format of
 * arguments
 * Return: count of printed characters
 */
int _printf(const char *format, ...)
{
	va_list to_be_printed;
	int chars, bpos, *ptrblen, *ptrbpos, blen;
	char buffer[1024];
	char_funcs con[] = {{"c", print_char},
		{"s", print_str},
		{"i", print_integr},
		{"d", print_integr},
		{"u", print_u},
	};
	va_start(to_be_printed, format);
	init_buf(buffer);
	chars = bpos = 0;
	blen = 1;
	ptrblen = &blen;
	ptrbpos = &bpos;
	if ((format[0] == '%' && format[1] == ' ')
		       	|| format == NULL
			|| to_be_printed == NULL
			|| format[0] =='%')
	{
		return (-1);
	}
	chars = formatp(format, to_be_printed,
			buffer, ptrblen, ptrbpos,
			con);
	write_buf(buffer, ptrblen, ptrbpos);
	va_end(to_be_printed);
	return (chars);
}

