#include "main.h"

t_matrix identity(void)
{
	int			r;
	int			c;
	t_matrix	I;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			if (c == r)
				I.M[r][c] = 1;
			else
				I.M[r][c] = 0;
		}
	}
	return (I);
}
