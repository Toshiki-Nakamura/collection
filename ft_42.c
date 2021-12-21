#include <stdio.h>

typedef	unsigned long	t_unsigned_long;

int		i = 0;
int		t = 1;
int		y = 3;

#define	I	++i
#define	Y	++i

void	ft_put42()
{
	int		f;
	int		o;
	int		u;
	t_unsigned_long	r;
			I;
			I;

	t_unsigned_long	T;
			I;
	t_unsigned_long	W;
	Y;
	t_unsigned_long	O;

	f = 3, o = 5, u = 2, r = 7, T = 5, W = 7, O = 8;
	printf("%lu\n", f + o + u + r + T + W + O + ++i);
}

int		main()
{
	ft_put42();
}