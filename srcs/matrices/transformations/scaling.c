#include "main.h"

t_matrix	scaling_matrix(double x, double y, double z)
{
	t_matrix	matrix;

	matrix = identity();
	matrix.m[0][0] = x;
	matrix.m[1][1] = y;
	matrix.m[2][2] = z;
	return (matrix);
}

t_tup	scale(t_tup point, double x, double y, double z)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = scaling_matrix(x, y, z);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}

t_tup	inverse_scale(t_tup point, double x, double y, double z)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = inverse(scaling_matrix(x, y, z), 4);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}
