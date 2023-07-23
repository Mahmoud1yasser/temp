#include "main.h"
/**
 * print_number - Copy one digit at a time to the buffer
 * @n: The integer to print
 * @buffer: Buffer
 * @len: Length of the buffer,
 * @pos: Position in the buffer
 *
 * Return: Number of characters printed
 */
int print_number(int n, char buffer[], int *len, int *pos)
{
	int chars = 0, sign = 0;

	if (*len < 1024)
	{
		if (n == 0)
		{
			buffer[*pos] = '0';
			*pos += 1;
			*len += 1;
			if (*len == 1024)
				write_buf(buffer, len, pos);
			return (1);
		}
		else if (n > 0)
			n *= -1;
		else
		{
			buffer[*pos] = '-';
			*pos += 1;
			*len += 1;
			if (*len == 1024)
				write_buf(buffer, len, pos);
			sign = 1;
		}
		if ((n / 10) != 0)
		{
			chars = print_number(((n / 10) * -1), buffer, len, pos);
		}
		buffer[*pos] = (n % 10) * -1 + '0';
		*len += 1;
		*pos += 1;
		if (*len == 1024)
			write_buf(buffer, len, pos);
		if (sign > 0)
			chars += sign;
		chars++;
		}
	else
	{
		write_buf(buffer, len, pos);
		if (n == 0)
		{
			buffer[*pos] = '0';
			*pos += 1;
			*len += 1;
			if (*len == 1024)
				write_buf(buffer, len, pos);
			return (1);
		}
		else if (n > 0)
			n *= -1;
		else
		{
			buffer[*pos] = '-';
			*pos += 1;
			*len += 1;
			if (*len == 1024)
				write_buf(buffer, len, pos);
			sign = 1;
		}
		if ((n / 10) != 0)
		{
			chars = print_number(((n / 10) * -1), buffer, len, pos);
		}
		buffer[*pos] = (n % 10) * -1 + '0';
		*pos += 1;
		*len += 1;
		if (*len == 1024)
			write_buf(buffer, len, pos);
		if (sign > 0)
			chars += sign;
		chars++;
		}
	return (chars);
}

/**
 * print_Unum - Copy unsigned integer to buffer
 * @n: Integer to copy
 * @buffer: Buffer to copy to
 * @len: Current length of buffer, # of characters in buffer
 * @pos: Current position in the buffer
 *
 * Return: Number of characters printed
 */
int print_Unum(unsigned int n, char buffer[], int *len, int *pos)
{
	int num_Chars;

	num_Chars = 0;

	if (*len < 1024)
	{
		if (n == 0)
		{
			buffer[*pos] = '0';
			*pos += 1;
			*len += 1;
			if (*len == 1024)
				write_buf(buffer, len, pos);
			return (1);
		}
		if ((n / 10) != 0)
			num_Chars = print_Unum((n / 10), buffer, len, pos);
		buffer[*pos] = (n % 10) + '0';
		*pos += 1;
		*len += 1;
		if (*len == 1024)
			write_buf(buffer, len, pos);
		num_Chars++;
	}
	else
	{
		write_buf(buffer, len, pos);
		if (n == 0)
		{
			buffer[*pos] = '0';
			*pos += 1;
			*len += 1;
			if (*len == 1024)
				write_buf(buffer, len, pos);
			return (1);
		}
		if ((n / 10) != 0)
			num_Chars = print_Unum((n / 10), buffer, len, pos);
		buffer[*pos] = (n % 10) + '0';
		*pos += 1;
		*len += 1;
		if (*len == 1024)
			write_buf(buffer, len, pos);
		num_Chars++;
	}
	return (num_Chars);
}
