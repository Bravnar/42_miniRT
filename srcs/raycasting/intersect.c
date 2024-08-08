#include "main.h"

double	discriminant(t_obj *shape, double *a, double *b)
{
	t_tup	sphere_to_ray;
	double	c;

	sphere_to_ray = tuple_sub(shape->saved_ray.point, shape->point);
	*a = dot(shape->saved_ray.direction, shape->saved_ray.direction);
	*b = 2 * dot(shape->saved_ray.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	return (*b * *b - 4 * *a * c);
}

t_intersection	intersection(double t, t_obj *shape)
{
	t_intersection	inter;

	inter.shape = shape;
	inter.t = t;
	return (inter);
}

t_inter	intersections(int c, ...)
{
	va_list	intersects;
	int		i;
	t_inter	inters;

	inters.i = malloc(sizeof(t_intersection) * (c + 1));
	if (!inters.i)
	{
		inters.i = NULL;
		return (inters);
	}
	va_start(intersects, c);
	inters.count = c;
	i = 0;
	while (i < c)
		inters.i[i++] = va_arg(intersects, t_intersection);
	va_end(intersects);
	inters.i[i].shape = NULL;
	return (inters);
}

t_inter	intersect(t_obj *shape)
{
	double	disc;
	double	a;
	double	b;
	t_inter	i;

	disc = discriminant(shape, &a, &b);
	if (disc < 0)
	{
		i.count = 0;
		return (i);
	}
	i.i = malloc(sizeof(t_intersection) * (2 + 1));
	if (!i.i)
	{
		i.i = NULL;
		return (i);
	}
	i.i[0] = intersection((-b - sqrt(disc)) / (2 * a), shape);
	i.i[1] = intersection((-b + sqrt(disc)) / (2 * a), shape);
	i.count = 2;
	return (i);
}
