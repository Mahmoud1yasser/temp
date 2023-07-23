#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct char_func - structure to find functions based on char
 *
 * @c: char to be checked as key.
 *
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
int print_s(va_list, char *, int *, int *);
int print_int(va_list, char *, int *, int *);
int print_u(va_list, char *, int *, int *);
int print_number(int, char *, int *, int *);
int print_Unum(unsigned int, char *, int *, int *);
int print_u(va_list, char *, int *, int *);
int print_o(va_list, char *, int *, int *);
int print_hex(va_list, char *, int *, int *);
int print_heX(va_list, char *, int *, int *);
int print_b(va_list, char *, int *, int *);
int print_S(va_list, char *, int *, int *);
int print_r(va_list, char *, int *, int *);
int print_R(va_list, char *, int *, int *);
int print_p(va_list, char *, int *, int *);
char *binConverter(unsigned int);
char *octConverter(unsigned int);
char *hexConverter(char, unsigned int);
char *size_tHex(char, size_t);
void write_buffer(char *, int *, int *);

#endif
