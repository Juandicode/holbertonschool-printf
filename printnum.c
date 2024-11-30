#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 *
 */
int printnumd(int a)
{
	int b, contador = 0;
	char c;

	if (a == INT_MIN)
	{
		write(1, "-", 1);
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
		return (11);
	}
	if (a < 0)
	{
		a = -a;
		write(1, "-", 1);
		contador++;
	}
	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	c = (a % 10) + '0';
	b = a / 10;
	if (b != 0)
	{
		contador += printnumd(b);
	}
	write(1, &c, 1);
	return (contador + 1);
}
