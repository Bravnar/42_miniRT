#include "main.h"

t_matrix	sub(t_matrix A, int size, int ex)
{
	t_matrix	sub;
	int			r;
	int			c;
	int			i;
	int			j;

	r = 0;
	i = 0;
	while (++r < size + 1)
	{
		c = -1;
		j = 0;
		while (++c < size + 1)
		{
			if (c == ex)
				continue ;
			sub.M[i][j++] = A.M[r][c];
		}
		i++;
	}
	return (sub);
}

double	determinant(t_matrix A, int size)
{
	int			i;
	double		result;
	t_matrix	subm;

	i = -1;
	result = 0;
	if (size == 2)
		return (A.M[0][0] * A.M[1][1] - A.M[0][1] * A.M[1][0]);
	while (++i < size)
	{
		subm = sub(A, size - 1, i);
		result += pow(-1, i) * determinant(subm, size - 1) * A.M[0][i];
	}
	return (result);
}
