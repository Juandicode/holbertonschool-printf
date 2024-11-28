#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 *
 */
void printch(char c, int *contador)
 {
 	write(1, &c, 1);
 	(*contador)+
 }
/**
 *
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
 *
 */
void printpercent(int *contador)
{
	write(1, "%", 1);
	(*contador)++;
}
/**
 *
 */
int _printf(const char *format, ...)
{
	int i = 0, contador = 0;
	va_list arg;
	
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
					printch(va_arg(arg, int *), &contador);
					break;
				case 's':
					printstr(va_arg(arg, char *), &contador);
					break;
				case '%':
					printpercent(&contador);
			}
		}
	}
	va_end(arg);
	return (contador);
}
