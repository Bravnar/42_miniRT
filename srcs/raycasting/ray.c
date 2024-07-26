#include "main.h"

t_ray	ray_new(t_tup point, t_tup direction)
{
	t_ray	ray;

	ray.point = point;
	ray.direction = direction;
	return (ray);
}

t_tup	position(t_ray ray, double t)
{
	t_tup	pos;

	pos = tuple_add(ray.point, scale(ray.direction, t, t, t));
	return (pos);
}
