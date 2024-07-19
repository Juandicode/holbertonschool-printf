#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/*
 * _printf - eugkjbgfd
 * - printea un caracter, un string y un %
 * @format: puntero al string
 * Return: Contador
 */
int _printf(const char *format,...)
{
    int contador = 0;
    va_list args;
    char c;
    char *s;

    if (*format == '\0') {
        return 0; /* or some other default value */
    }
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
                    write(1, format - 1, 1);
                    contador++;
                    break;
            }
        } else {
            write(1, format, 1);
            contador++;
        }
    }
    va_end(args);
    return contador;
}
