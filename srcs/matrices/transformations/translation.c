#include "main.h"

t_matrix	translation_matrix(double x, double y, double z)
{
	t_matrix	matrix;

	matrix = identity();
	matrix.M[0][3] = x;
	matrix.M[1][3] = y;
	matrix.M[2][3] = z;
	return (matrix);
}

t_tup	translate(t_tup point, double x, double y, double z)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = translation_matrix(x, y, z);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}

t_tup	inverse_translate(t_tup point, double x, double y, double z)
{
	t_tup transformed;
	t_matrix transformation_matrix;

	transformation_matrix = inverse(translation_matrix(x, y, z), 4);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}
