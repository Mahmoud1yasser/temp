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
	for (j = 0; j < 13; j++)
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
/** formatprinter - function search in string format for the %.
 * @format: string which contains list of % indentifier.
 * Return: position of identifier.
 */
void formatprinter(const char *format,va_list to_be_printed, char_funcs conversion[],char buffer[], int *buflenptr, int *bufposptr)
{
	int pos;

	for (pos = 0; str != '\0' && str != NULL; pos++)
	{
		if (format[pos] == '%')
		{
			print = check_conversion(format[pos + 1], char_func_t conversions[], buffer[], buflen, bufpos);
			if (print == 0)
			{
				chars += copy_to_buffer(format[i], buffer, buflenptr, bufposptr);
			}
			chars += print;
		}
		else if (str[ident_pos] == '\\')
		{
			/* to check for new line if exist*/
		}
		else
		{
		 	/* copy to buffer*/
			/* increase count of printed chars*/
			chars += copy_to_buffer(format[i],
					buffer, buflenptr, bufposptr);
		}
	}
}

/**
 * _printf - clone for original printf
 * @format: pointer for format of
 * arguments
 * Returns: count of printed characters
 */
int _printf(const char *format, ...)
{
	va_list to_be_printed;

	initialize_buffer(buffer);
	chars = bufpos = 0;
	buflen = 1;
	buflenptr = &buflen;
	bufposptr = &bufpos;
	/* should be moved up as its decleration*/
	char_funcs conversions[] = {{"c", print_c},
		{NULL, NULL},
	};
	formatprinter(format, print_this,
			buffer, buflenptr, bufposptr,
			conversions);
	va_start(to_be_printed, format);
	va_end(to_be_printed);

}
