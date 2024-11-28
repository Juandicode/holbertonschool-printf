#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 *
 */
char printstr(char *s, int *contador)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		write(1, &s[i], 1);
	}
}
/**
 *
 */
int _printf(const char *format, ...)
{
	int i = 0, contador = 0;
	va_list arg;
	char c;
	
	va_start(arg, format);
	for (; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			contador++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(arg, int);
					write(1, &c, 1);
					contador++;
					break;
				case 's':
					printstr(va_arg(arg, char *), &contador);
					break;
			}
		}
	}
	return (1);
}
