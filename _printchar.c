#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/*
 * _printf - eugkjbgfd
 * - printea un caracter, un string y un %
 * @format: puntero al string
 * Return: Contador
 */
int _printf(const char *format, ...)
{
	int contador = 0;
	int i;
	va_list args;
	char *s;
	char c;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
	if (format[i] == '%')
	{
	if (format[i + 1] != '\0')
	{
	i += 1;
	if (format[i] == 'c')
	{
	c = va_arg(args, int);
	write(1, &c, 1);
	contador++;
	}
	else if (format[i] == '%')
	{
	write(1, "%", 1);
	contador++;
	}
	else if (format[i] == 's')
	{
	s = va_arg(args, char *);
	contador = contador + write(1, s, _strlen(s));
	}
	}
	}
	else
	{
	write(1, &format[i], 1);
	contador++;
	}
	}
	va_end(args);
	return (contador);
}
