#include "main.h"

double	determinant(t_matrix A, int size, int r, int c)
{
	int		i;
	int		j;
	int		k;
	double	result;

	i = -1;
	result = 0;
	if (size == 2)
	{
		j = -1;
		k = 0;
		while (++j < size + 1)
		{
			if (j == c)
				continue ;
			if (k == 0)
				result += A.M[r][c + 1] * A.M[r + 1][c + 1];
			else
				result -= A.M[r + 1][c ] * A.M[];
			k++;
		}
	}
	while (++i < size)
		result += pow(-1, i) * determinant(A, size - 1, 4 - size, i) * A.M[r][c + i];
	return (result);
}
