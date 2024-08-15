#include "main.h"

t_matrix	rotation_x(double deg)
{
	t_matrix	matrix;
	double		rad;

	rad = deg / 180 * M_PI;
	matrix = identity();
	matrix.m[1][1] = cos(rad);
	matrix.m[1][2] = -sin(rad);
	matrix.m[2][1] = sin(rad);
	matrix.m[2][2] = cos(rad);
	return (matrix);
}

t_matrix	rotation_y(double deg)
{
	t_matrix	matrix;
	double		rad;

	rad = deg / 180 * M_PI;
	matrix = identity();
	matrix.m[0][0] = cos(rad);
	matrix.m[0][2] = sin(rad);
	matrix.m[2][0] = -sin(rad);
	matrix.m[2][2] = cos(rad);
	return (matrix);
}

t_matrix	rotation_z(double deg)
{
	t_matrix	matrix;
	double		rad;

	rad = deg / 180 * M_PI;
	matrix = identity();
	matrix.m[0][0] = cos(rad);
	matrix.m[0][1] = -sin(rad);
	matrix.m[1][0] = sin(rad);
	matrix.m[1][1] = cos(rad);
	return (matrix);
}

t_tup	rotate(t_tup point, double deg, char axis)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	if (axis == 'x')
		transformation_matrix = rotation_x(deg);
	else if (axis == 'y')
		transformation_matrix = rotation_y(deg);
	else
		transformation_matrix = rotation_z(deg);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}

t_tup	inverse_rotate(t_tup point, double deg, char axis)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	if (axis == 'x')
		transformation_matrix = inverse(rotation_x(deg), 4);
	else if (axis == 'y')
		transformation_matrix = inverse(rotation_y(deg), 4);
	else
		transformation_matrix = inverse(rotation_z(deg), 4);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}
