#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
* _printf - prints anything
* @format: the format string to print
*
* Return: the number of bytes printed
*/

int _printf(const char *format, ...)
{
	va_list arguments;
	size_t bytes_written;
	char character, *string;
	int i;

	i = 0;
	bytes_written = 0;

	va_start(arguments, format);

	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			if (format[i] != '%')
			{
				bytes_written += write(1, (format + i), 1);
			}
			else
			{
				if (format[i + 1] == 'c')
				{
					character = va_arg(arguments, int);
					bytes_written += write(1, &character, 1);
					i += 2;
					continue;
				}
				else if (format[i + 1] == 's')
				{
					string = va_arg(arguments, char *);
					bytes_written += write(1, string, strlen(string));
					i += 2;
					continue;
				}
				else if (format[i + 1] == '%')
				{
					character = '%';
					bytes_written += write(1, &character, 1);
					i += 2;
					continue;
				}
			}
			i++;
		}
	}

	va_end(arguments);

	return (bytes_written);
}
