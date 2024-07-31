#include "main.h"

t_ray	ray_transform(t_ray ray, t_matrix transform)
{
	t_ray	result;

	result.direction = matrix_mult_tup(transform, ray.direction);
	result.point = matrix_mult_tup(transform, ray.point);
	return (result);
}
