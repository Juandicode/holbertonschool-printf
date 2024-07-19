#include <stdio.h>
#include "main.h"

int _printf(const char *format,...);

int main(void)
{
    int len;
    int len2;

    len = _printf("Hello, World!\n");
    len2 = printf("Hello, World!\n");

    printf("Length:[%d, %d]\n", len, len2);

    _printf("%c\n", 'H');
    printf("%c\n", 'H');

    _printf("%s\n", "Hello");
    printf("%s\n", "Hello");

    _printf("%%\n");
    printf("%%\n");

    _printf("%c%c\n", 'H', 'e');
    printf("%c%c\n", 'H', 'e');

    _printf("%s %s\n", "Hello", "World");
    printf("%s %s\n", "Hello", "World");

	int len234234 = _printf("%");

	printf("%d", len234234);
	int len234233 = printf("%");

        printf("%d", len234233);

    return (0);
}
