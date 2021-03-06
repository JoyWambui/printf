#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct structprint - structure containing
 * @q: the location and method to translate data to characters.
 * @u: print function for specific type.
 *
 * Return: int
 */
typedef struct structprint
{
	char *q;
	int (*u)(char *format, va_list);
} structype;

int _putchar(char ch);
int (*driver(char *format))(char *format, va_list);
int _printf(char *format, ...);
char *itoa(int num, char *buffer, int base);
char *reverse(char *buffer, int i, int j);
void swap(char *x, char *y);

#endif
