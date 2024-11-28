#include <stdio.h>
#include <unistd.h> /* para la función write*/
#include "main.h"
#include <stdarg.h>  
#include <limits.h>  /*para los casos bordes */
/**
 * _printf - imprime caracteres, strings, y %
 * @format: puntero a un string
 * Return: contador
 */
int print_int(int n)
{
	int contador = 0;   /* arranco el contador del largo del int en 0 */
	char str[12];       /* el tamao es 10 porque el maximo int es 2147483648 */
	int i = 0;          /* lo uso para moverme en el arreglo str */

	if (n == INT_MIN)
		{
		write(1, "-", 1); /* imprimo el simbolo negativo */
		write(1, "2", 1);
		write(1, "1", 1);
		write(1, "4", 1);
		write(1, "7", 1);
		write(1, "4", 1);
		write(1, "8", 1);
		write(1, "3", 1);
		write(1, "6", 1);
		write(1, "4", 1);
		write(1, "8", 1);
		contador = 11;
		}
				else if (n == INT_MAX)
			{
			write(1, "2", 1);
			write(1, "1", 1);
			write(1, "4", 1);
			write(1, "7", 1);
			write(1, "4", 1);
			write(1, "8", 1);
			write(1, "3", 1);
			write(1, "6", 1);
			write(1, "4", 1);
			write(1, "7", 1);
			contador = 10;
			}
				else
{
    

    				if (n == 0)         /*si es 0 el numero */
    					{
        				write(1,"0",1); /*imprimo 0*/
        				return 1;       /* el largo es 1*/
    					}

    if (n < 0)        /* si n es negativo */
    {
        write(1,"-",1); /* imprimo el simbolo negativo */
	n = -n;         /* cambio el signo de n */
        contador++;        /* aumento el contador por el simbolo de - */
    }


    while (n > 0)
    {
        str[i] = (n % 10) + '0';        /* guardo en el lugar i de str el resto de la division entera entre n y 10, le sumo '0' para pasarlo a tabla ASCII */
        n = n/10;                       /* divido n entre 10 */
        i++;
    }
while (i > 0)                       /* leo el arreglo de adelante para atras y voy imprimiendo el valor */
    {
        write(1, &str[--i], 1);
        contador++;
    }
  
	}
    return (contador);
}

int _printf(const char *format, ...) 
{
	int contador = 0, i, j;  /* declaracion de variables de tipo int */
	va_list args;                  /*declaracion de variable q almacenara la lista de argumentos variables */
	char c, *s; /*declaracion de variables de tipo char */ 

	va_start(args, format);          /* inicializa la lista de argumentos variables almacenada en 'args' a partir del parametro format */
	for (i = 0; format[i] != '\0'; i++)   /*recorre el string format caracter por caracter hasta llegar al final del string */
	{
		if (format[i] == '%' && format[i + 1] != '\0')   /* verifica si el caracter actual es un % y si el siguiente no es el final del string */
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int); /* estaa linea utiliza la macro va_arg para obtener el proximo argumento de la lista de argumentos variables 'args' */
				write(1, &c, 1);
				contador++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *); /* utilizo la macro va_arg para obtener el proximo argumento de la lista de armts vrbls, que se almacena en la variable s que es un puntero a un string */
				if (s == NULL)    /* es null? */
					s = "(null)"; /* entonces retorna null */
				for (j = 0; s[j]; j++, contador++) /* inicia un bucle for hatsa el final de la cadena */
					write(1, &s[j], 1);   /* imprime cada caracter de la cadena s, &s[j] es la direccion de memoria del caracter actual  */
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				contador++;
			}
			else if (format[i] == 'd' || format[i] == 'i')    
			{
                		contador += print_int(va_arg(args, int));       /* llamo a la funcion para que imprima el int y le sume su largo a la variable contador */
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

