#include "header_functions.h"

/**
 * _printf - clone for original printf
 * @format: pointer for format of
 * arguments
 * Returns: count of printed characters
 */
int _printf(const char *format, ...)
{
	va_list to_be_printed;
	char_funcs conversions[] = {{"c", print_c},
		{"s", print_s},
		{"i", print_int},
		{"d", print_int},
		{"u", print_u},
		{"o", print_o},
		{"x", print_hex},
		{"X", print_heX},
		{"b", print_b},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{"p", print_p},
		{NULL, NULL},
	};
	va_start(to_be_printed, format);
	va_end(to_be_printed);

}
