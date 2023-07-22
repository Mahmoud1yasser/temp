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
int print_c(va_list, char *, int, int);
void write_buffer(char *, int, int);
void initialize_buffer(char );
int copy_to_buffer(char formatter, char buffer[], int *, int*);
int check_conversion(char formatter, char_funcs_t conversions[], char buffer[], int *, int *, va_list)
