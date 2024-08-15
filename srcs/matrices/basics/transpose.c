#include "main.h"

t_matrix	transpose(t_matrix A)
{
	t_matrix	t;
	int			r;
	int			c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
			t.m[c][r] = A.m[r][c];
	}
	return (t);
}
