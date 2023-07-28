#include <stdio.h>
#include "main.h"
/**
 * my_printf - Custom printf function for conversion specifiers 'd' and 'i'
 * @format: Format string containing the conversion specifier
 * @num: The integer value to be printed
 *
 * Return: The number of characters printed
 */
int my_printf(const char *format, int num)
{
	int count = 0;

	if (format != NULL)
	{
		while (*format)
		{
			if (*format == '%' && *(format + 1) == 'd')
			{
				printf("%d", num);
				count++;
				format++;
			}
			else if (*format == '%' && *(format + 1) == 'i')
			{
				printf("%i", num);
				count++;
				format++;
			}
			else
			{
				putchar(*format);
				count++;
			}
			format++;
		}
	}

	return (count);
}
