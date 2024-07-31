#include "main.h"

t_tup	normal_at(t_obj *sphere, t_tup point)
{
	t_tup	object_point;
	t_tup	object_normal;
	t_tup	world_normal;

	object_point = matrix_mult_tup(sphere->inverse_transformation, point);
	object_normal = tuple_sub(object_point, sphere->point);
	world_normal = matrix_mult_tup(transpose(
				sphere->inverse_transformation), object_normal);
	world_normal.w = 0;
	return (vector_norm(world_normal));
}
