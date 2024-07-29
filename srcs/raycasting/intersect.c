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

t_inter	intersect_sphere(t_ray r, t_obj *sphere)
{
	double	disc;
	double	a;
	double	b;
	t_ray	inv_ray;
	t_inter	i;

	inv_ray = ray_transform(r, sphere->inverse_transformation);
	disc = discriminant(inv_ray, sphere, &a, &b);
	if (disc < 0)
	{
		i.count = 0;
		return (i);
	}
	i.i = malloc(sizeof(t_intersection) * (2 +1));
	if (!i.i)
	{
		i.i = NULL;
		return (i);
	}
	i.i[0] = intersection((-b - sqrt(disc)) / 2 * a, sphere);
	i.i[1] = intersection((-b + sqrt(disc)) / 2 * a, sphere);
	i.count = 2;
	return (i);
}

