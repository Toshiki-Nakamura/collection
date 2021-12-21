#include <stdio.h>

int	i = 2;
#define I ++i

unsigned long	get42()
{
	int           f;
	int           o;
	int           u;
	unsigned long r;
	              I;
	              I;

	unsigned long T;
	              I;
	unsigned long W;
	I;
	unsigned long O;

	f = 7, o = 7, u = 7, r = 7, T = 7, W = 7, O = 7-I;
	return (f + o + u + r + T + W + O);
}

int		main()
{
	printf("%lu", get42());
}