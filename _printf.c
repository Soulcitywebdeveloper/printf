#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * _printf - function that produces output according to a format.
 * @format: character string with the format to print.
 *
 * Return: the num of characters printed
 */
int _printf(const char *format, ...)
{
	/* declarations */
	int i = 0, count = 0;
	va_list arglist;

	/* initialize variable list */
	va_start(arglist, format);

	/* loop through format string and print */
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			/* handle conversion specifier */
			switch (format[i + 1])
			{
				case 'c':
					count += _putchar(va_arg(arglist, int));
					break;
				case 's':
					count += _puts(va_arg(arglist, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					/* print literal % */
					count += _putchar(format[i]);
					count += _putchar(format[i + 1]);
					break;
			}
			i += 2;
		}
		else
		{
			count += _putchar(format[i]);
			i++;
		}
	}
	va_end(arglist);
	return (count);
}

/**
 * _putchar - function to print a character.
 * @c: character to print.
 *
 * Return: 1 on success, -1 on error.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function to print a string.
 * @str: string to print.
 *
 * Return: the number of characters printed.
 */
int _puts(char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
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
