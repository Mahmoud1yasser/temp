#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdarg.h>
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
#endif
