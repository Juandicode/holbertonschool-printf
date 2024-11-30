#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * printch - prints a char
 * @c: char a imprimir
 * @contador: un puntero a la variable contador de _printf
 */
void printch(char c, int *contador)
{
	write(1, &c, 1);
	(*contador)++;
}

/**
 * printstr - prints a char
 * @s: pointer to the char
 * @contador: pointer to the variable cntador para iterar cada caracter
 * Return: size of the string
 */
int printstr(char *s, int *contador)
{
	int i;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		write(1, &s[i], 1);
		(*contador)++;
	}

	return (i);
}
/**
 * printpercent - print the percent simbol
 * @contador: pointer to a variable to iterate
 */
void printpercent(int *contador)
{
	write(1, "%", 1);
	(*contador)++;
}
/**
 * _printf - a function to prin chars, ints, and strings
 * @format: pointer to a string to be printed
 * Return: amount of charactes printed
 */
int _printf(const char *format, ...)
{
	int i, contador = 0;
	va_list arg;

	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%' && format[i] != '\\')
		{
			write(1, &format[i], 1);
			contador++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					printch(va_arg(arg, int), &contador);
					break;
				case 's':
					printstr(va_arg(arg, char *), &contador);
					break;
				case '%':
					printpercent(&contador);
					break;
				case 'd':
					contador = contador + printnumd(va_arg(arg, int));
					break;
				case 'i':
					contador = contador + printnumd(va_arg(arg, int));
					break;
			}
		}
		else if (format[i] == '\\')
		{
			i++;
			if (format[i] == 'n')
				write(1, "\n", 1);
		}
	}
	va_end(arg);
	return (contador);
}
