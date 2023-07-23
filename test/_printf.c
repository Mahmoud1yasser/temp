#include "header_functions.h"
/**
* copy_to_buffer - Copies the given character over to the buffer
* @formatter: Character to copy over
* @buffer: Buffer being copied to
* @buflenptr: Pointer to the length of the buffer, the number of
* characters in the buffer
* @bufposptr: Pointer to the position in the buffer
*
* Return: Number of characters copied to buffer
*/
int copy_to_buffer(char formatter, char buffer[],
		     int *buflenptr, int *bufposptr)
{
	int chars;

	chars = 0;
	buffer[*bufposptr] = formatter;
	*bufposptr += 1;
	*buflenptr += 1;
	if (*buflenptr == 1024)
	{
		write_buffer(buffer, buflenptr, bufposptr);
	}
	chars++;
	return (chars);
}


/**
* check_conversion - Checks formatter character to see if
* it's a conversion specifier
* @formatter: The format character being checked
* @conversions: Struct holding conversion specifiers & function pointers to
* @appropriate functions for corresponding conversion specifier
* @buffer: Buffer needed to copy to when calling function
* @buflenptr: Pointer to the length of the buffer
* @bufposptr: Pointer to the position within the buffer
* @print_this: va_list holding all given arguments to _printf function
*
* Return: Return the number of characters copied to buffer if a
* function is called, 0 if no function is called
*/
int check_conversion(char formatter, char_funcs conversions[], char buffer[],
		     int *buflenptr, int *bufposptr, va_list print_this)
{
	int j, chars;

	chars = 0;
	for (j = 0; j < 2; j++)
	{
		if (formatter == *conversions[j].c)
		{
			chars += conversions[j].f(print_this, buffer, buflenptr,
						  bufposptr);
			return (chars);
		}
	}
	return (0);
}
/**
 * formatprinter - function search in string format for the %.
 * @format: string which contains list of % indentifier.
 * @to_be_printed: arguments in printf
 * @buffer: memory for printing
 * @buflenptr: pointer to buffer length
 * @bufposptr: pointer to current 
 * position in buffer
 * @conversions: pointer to format func.
 * Return: position of identifier.
 */
int formatprinter(const char *format,
		va_list to_be_printed, char buffer[],
		int *buflenptr, int *bufposptr,
		char_funcs conversions[])
{
	int pos, print, chars;

	for (pos = 0; format[pos] != '\0' && format != NULL; pos++)
	{
		if (format[pos] == '%')
		{
			pos++;
			print = check_conversion(format[pos],
					conversions, buffer, buflenptr,
					bufposptr, to_be_printed);
			if (print == 0)
			{
				chars += copy_to_buffer(format[pos],
						buffer, buflenptr, bufposptr);
			}
			chars += print;
		}
		else
		{
			chars += copy_to_buffer(format[pos],
					buffer, buflenptr, bufposptr);
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
	int chars, bufpos, *buflenptr, *bufposptr, buflen;
	char buffer[1024];
	char_funcs conversions[] = {{"c", print_c},
		{"s", print_s}};
	va_start(to_be_printed, format);
	initialize_buffer(buffer);
	chars = bufpos = 0;
	buflen = 1;
	buflenptr = &buflen;
	bufposptr = &bufpos;
	if (format == NULL || to_be_printed == NULL)
	{
		return (chars);
	}
	formatprinter(format, to_be_printed,
			buffer, buflenptr, bufposptr,
			conversions);
	write_buffer(buffer, buflenptr, bufposptr);
	va_end(to_be_printed);
	return (chars);
}

