#include "main.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	/*char c = 'a';
	  char *str = "Bye"; */
	int len;
	int len2;
	unsigned int ui;
	char c = 'A';
	char s[] = "Mahmoud";

	ui = (unsigned int)INT_MAX + 1024;
	_printf("this is a character a in capital %c \n", c);
	_printf("this is my name %s \n", s);
	_printf("this is a to print %%\n");
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);

	return (0);
}
