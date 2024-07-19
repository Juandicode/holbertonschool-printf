#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - prints output according to format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int contador = 0;
    va_list args;
    char c;
    char *s;

    va_start(args, format);
    for (; *format; format++) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    contador++;
                    break;
                case '%':
                    write(1, "%", 1);
                    contador++;
                    break;
                case 's':
                    s = va_arg(args, char *);
                    if (s == NULL) {
                        contador += write(1, "(null)", 6);
                    } else {
                        contador += write(1, s, _strlen(s));
                    }
                    break;
                default:
                    write(1, "%", 1);
                    contador++;
                    break;
            }
        } else {
            write(1, format, 1);
            contador++;
        }
    }
    va_end(args);
    return (contador);
}
