#include "main.h"

void print_matrix(t_matrix matrix, int size)
{
	int	r;
	int	c;

	r = -1;
	while (++r < size)
	{
		c = -1;
		while (++c < size)
			printf("%f ", matrix.M[r][c]);
		printf("\n");
	}
}

void	print_column(t_column column)
{
	int	r;

	r = -1;
	while (++r < 4)
		printf("%f\n", column.m[r]);
}
