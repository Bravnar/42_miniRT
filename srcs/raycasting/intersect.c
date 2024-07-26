#include "main.h"

double	discriminant(t_ray r, t_obj *sphere, double *a, double *b)
{
	t_tup	sphere_to_ray;
	double	c;

	sphere_to_ray = tuple_sub(r.point, sphere->point);
	*a = dot(r.direction, r.direction);
	*b = 2 * dot(r.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	return (*b * *b - 4 * *a * c);
}

t_inter	intersect(t_ray r, t_obj *sphere)
{
	double	disc;
	double	a;
	double	b;
	t_inter	i;

	disc = discriminant(r, sphere, &a, &b);
	if (disc < 0)
	{
		i.count = 0;
		return (i);
	}
	i.t[0] = (-b - sqrt(disc)) / 2 * a;
	i.t[1] = (-b + sqrt(disc)) / 2 * a;
	i.count = 2;
	return (i);
}
