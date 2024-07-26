#include "main.h"

t_matrix	transpose(t_matrix A)
{
	t_matrix	T;

	int	r;
	int	c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
			T.M[c][r] = A.M[r][c];
	}
	return (T);
}
