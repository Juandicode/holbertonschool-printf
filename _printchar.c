#include <stdio.h>
#include <unistd.h> /* para la función write*/
#include "main.h"
#include <stdarg.h>
/**
 * _printf - imprime caracteres, strings, y %
 * @format: puntero a un string
 * Return: contador
 */
int _printf(const char *format, ...)
{
	int contador = 0, i, j;
	va_list args;
	char c, *s;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
	if (format[i] == '%' && format[i + 1] != '\0')
	{
	i++;
	if (format[i] == 'c')
	{
	c = va_arg(args, int);
	write(1, &c, 1);
	contador++;
	}
	else if (format[i] == 's')
	{
	s = va_arg(args, char *);
	if (s == NULL)
	s = "(null)";
	for (j = 0; s[j]; j++, contador++)
	write(1, &s[j], 1);
	}
	else if (format[i] == '%')
	{
	write(1, "%", 1);
	contador++;
	}
	else
	{
	contador = contador + write(1, &format[i - 1], 2);
	}
	}
	else if (format[i] == '%' && format[i + 1] == '\0')
	{
		return (-1);
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
