#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 *
 */
void printnumd(int a)
{
	int b;
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
		return;
	}
	if (a < 0)
	{
		a = -a;
		write(1, "-", 1);
	}
	else if (a == 0)
	{
	       return;
	}
	c = (a % 10) + '0';
	b = a / 10;
	if (a != 0)
	{
		printnumd(b);
	}
	write(1, &c, 1);
}
