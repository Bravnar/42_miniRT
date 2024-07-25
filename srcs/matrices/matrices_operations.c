#include "main.h"

bool	matrice_compare(t_matrix A, t_matrix B)
{
	int	r;
	int	c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			if (A.M[r][c] != B.M[r][c])
				return (false);
		}
	}
	return (true);
}

t_matrix	matrice_mult(t_matrix A, t_matrix B)
{
	t_matrix	result;

	int	r;
	int	c;
	int	i;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			i = -1;
			result.M[r][c] = 0;
			while (++i < 4)
				result.M[r][c] += A.M[r][i] * B.M[i][c];
		}
	}
	return (result);
}
t_column	matrice_mult_col(t_matrix A, t_column b)
{
	t_column	result;

	int	r;
	int	i;

	r = -1;
	while (++r < 4)
	{
		i = -1;
		result.m[r] = 0;
		while (++i < 4)
		{
			result.m[r] += A.M[r][i] * b.m[i];
		}
	}
	return (result);
}
