#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * char_func - structure to find functions based on char
 * @c: char to be checked as key.
 * @f: pointer to function to call.
 */

typedef struct char_func
{
	char *c;
	int (*f)();
} char_funcs;

int _printf(const char *, ...);
void initialize_buffer(char *);
int print_c(va_list, char *, int *, int *);
int print_string(va_list, char *, int *, int *);
void write_buffer(char *, int *, int *);
#endif
