#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_integr -copy number to the buffer
 *
 * @args: Va_list arguments to _printf
 *
 * @buffer: The buffer being copied to to print
 *
 * @len: The current length of the buffer aka number of characters in buffer
 *
 * @pos: Current position, or index, inside the buffer
 *
 * Return: Returns number of characters copied to buffer, allows for _printf to
 * return proper number of characters printed
 */

int print_integr(va_list args, char buffer[], int *len, int *pos)
{
	int chars;
	int num;

	num = va_arg(args, int);
	chars = print_number(num, buffer, len, pos);
	return (chars);
}

/**
* print_u - prints the unsigned int
* @args: number to be printed
*
* @buffer: space used for printing
*
* @len: buffer length
*
* @pos: current buffer index
*
* Return: numbers of chars written to buffer
**/
int print_u(va_list args, char buffer[], int *len, int *pos)
{
	unsigned int c;
	int chars;

	c = va_arg(args, unsigned int);
	chars = print_Unum(c, buffer, len, pos);
	return (chars);
}
