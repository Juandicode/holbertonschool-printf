#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
/*      
 *unsigned int ui;
	void *addr;

	(void) addr;*/

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");

	printf("%d", len);
	printf("%d", len2);

	_printf("%c", 'p');
	
	/*   
	 *   ui = (unsigned int)INT_MAX + 1024;
	 addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	
	*/

	printf("probando caso mas sencillo solo imprimir un caracter:\n");
	len =  _printf("%c", 'c');
	printf("\n");
	len2 = printf("%c", 'c');
	printf("\nel largo de len es = %d\n", len);
	printf("el largo de len2 es = %d\n", len2);

	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");

	printf("\n------------------------\n");
printf("probndo caso string y caso string y char juntos\n");
_printf("probndo caso string y caso string y char juntos\n");

_printf("hola\n");
_printf("hola %c\n", 'o');
printf("-----------------------------\n");
	
	return (0);
}
