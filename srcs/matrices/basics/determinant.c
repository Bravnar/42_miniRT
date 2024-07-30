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

/* USED TO OPTIMIZE THE DETERMINANT COMPUTATION TIME, THUS ONLY CODED TO TAKE MATRIX OF SIZE > 2 */
bool	is_triangular(t_matrix	A, int	size)
{
	int		i;
	int		j;
	bool	lower;
	bool	upper;

	i = -1;
	lower = true;
	upper = true;
	while (++i < size - 1)
	{
		j = 0 + i;
		if (!lower && !upper)
				break ;
		while (++j < size)
		{
			if (!lower && !upper)
				break ;
			if (upper)
				upper = !equal(A.M[i][j], 0);
			if (lower)
				lower = !equal(A.M[j][i], 0);
		}
	}
	return (lower || upper);
}

/*	Could have been used to speed up determinant computation but
	it showed little improvement overall
	during testing */

bool	has_zero_row_column(t_matrix A, int size)
{
	int	i;
	int	j;
	int	sum_r;
	int	sum_c;

	i = -1;
	sum_c = 1;
	sum_r = 1;
	while (++i < size && sum_r && sum_c)
	{
		sum_c = 0;
		sum_r = 0;
		j = -1;
		while (++j < size)
		{
			sum_r += A.M[i][j];
			sum_c += A.M[j][i];
		}
	}
	return (equal(sum_c, 0) || equal(sum_r, 0));
}

double	diagonal_product(t_matrix A, int size)
{
	int	i;
	int	product;

	i = -1;
	product = 1;
	while (++i < size)
		product *= A.M[i][i];
	return (product);
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
	if (is_triangular(A, size))
		return (diagonal_product(A, size));
	if (has_zero_row_column(A, size))
		return (0);
	while (++i < size)
	{
		if (A.M[0][i])
			continue ;
		subm = sub(A, size - 1, i);
		result += pow(-1, i) * determinant(subm, size - 1) * A.M[0][i];
	}
	return (result);
}
