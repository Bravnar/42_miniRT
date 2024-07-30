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

void	print_tuple(t_tup tuple)
{
	printf("(%f, %f, %f, %d)\n", tuple.x, tuple.y, tuple.z, tuple.w);
}

void	print_ray(t_ray ray)
{
	printf("Direction: ");
	print_tuple(ray.direction);
	printf("Point: ");
	print_tuple(ray.point);
}

void	print_cofactors(t_matrix A, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			printf("%f ",cofactor(A, i, j, size));
		printf("\n");
	}
}
