#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
/**
 * _printf - prints formatted data to stdout
 * @format: string that contains the format to print
 * Return: number of characters written
 */
int _printf(char *format, ...)
{
	char temp[30];
	char buffer[100] = {0};
	va_list ap;
	int count = 0;
	int i = 0;

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'd':
				itoa(va_arg(ap, int), temp, 10);
				strcpy(&buffer[count], temp);
				count += strlen(temp);
				break;
				break;
			case 'i':
				itoa(va_arg(ap, int), temp, 10);
				strcpy(&buffer[count], temp);
				count += strlen(temp);
				break;
			}
		}
		else
		{
			buffer[count] = format[i];
			count++;
		}
		i++;
	}
	write(1, buffer, count);
	va_end(ap);
	return count;
}

/**
 * swap- swaps two numbers
 * @x: pointer to first number
 * @y: pointer to second number
 */
void swap(char *x, char *y)
{
	char t = *x;
	*x = *y;
	*y = t;
}

/**
 * reverse - reverses a string
 * @buffer: string that contains the format to print
 * @i: starting index
 * @j: index from the end
 * Return: pointer to reversed string
 */
char *reverse(char *buffer, int i, int j)
{
	while (i < j)
	{
		swap(&buffer[i++], &buffer[j--]);
	}

	return buffer;
}

/**
 * itoa - converts an integer to string
 * @format: string that contains the format to print
 * Return: number of characters written
 */
char *itoa(int num, char *buffer, int base)
{
	int i = 0;
	int j;
	int k;

	if (base < 2 || base > 32)
	{
		return buffer;
	}

	k = abs(num);
	while (k)
	{
		j = k % base;
		if (j >= 10)
		{
			buffer[i++] = 65 + (j - 10);
		}
		else
		{
			buffer[i++] = 48 + j;
		}
		k = k / base;
	}
	if (i == 0)
	{
		buffer[i++] = '0';
	}
	if (num < 0 && base == 10)
	{
		buffer[i++] = '-';
	}

	buffer[i] = '\0';

	return reverse(buffer, 0, i - 1);
}