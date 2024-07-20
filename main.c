#include <stdio.h>
#include "main.h"

int _printf(const char *format,...);

int main(void)
{
    int len;
    int len2;
    int len234234 = _printf("%");
    int len234233 = printf("%");

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

	printf("%d", len234234);

        printf("%d\n\n", len234233);


	len = _printf("%!\n");
	printf("%d\n", len);

	len = printf("%!\n");
        printf("%d\n", len);

    return (0);
}
