#include "main.h"

bool	matrix_compare(t_matrix A, t_matrix B)
{
	int	r;
	int	c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			if (A.m[r][c] != B.m[r][c])
				return (false);
		}
	}
	return (true);
}

t_matrix	matrix_mult(t_matrix A, t_matrix B)
{
	t_matrix	result;
	int			r;
	int			c;
	int			i;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			i = -1;
			result.m[r][c] = 0;
			while (++i < 4)
				result.m[r][c] += A.m[r][i] * B.m[i][c];
		}
	}
	return (result);
}

t_column	matrix_mult_col(t_matrix A, t_column b)
{
	t_column	result;
	int			r;
	int			i;

	r = -1;
	while (++r < 4)
	{
		i = -1;
		result.m[r] = 0;
		while (++i < 4)
			result.m[r] += A.m[r][i] * b.m[i];
	}
	return (result);
}

t_tup	matrix_mult_tup(t_matrix A, t_tup b)
{
	t_column	temp;
	t_tup		result;
	int			r;

	r = -1;
	while (++r < 4)
	{
		temp.m[r] = A.m[r][0] * b.x;
		temp.m[r] += A.m[r][1] * b.y;
		temp.m[r] += A.m[r][2] * b.z;
		temp.m[r] += A.m[r][3] * b.w;
	}
	result.x = temp.m[0];
	result.y = temp.m[1];
	result.z = temp.m[2];
	result.w = temp.m[3];
	return (result);
}
