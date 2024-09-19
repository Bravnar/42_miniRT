/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 30/08/2024 13:47:24 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:00:35 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_inter	*new_inter(int count, t_obj *shape, ...)
{
	va_list	args;
	int		i;
	t_inter	*new;

	new = NULL;
	i = -1;
	va_start(args, shape);
	while (++i < count)
		add_inter_node(&new, new_inter_node(
				intersection(va_arg(args, double), shape)));
	va_end(args);
	return (new);
}

double	discriminant(t_obj *shape, double *a, double *b)
{
	t_tup	to_ray;
	double	c;

	to_ray = tuple_sub(shape->saved_ray.point, shape->point);
	*a = dot(shape->saved_ray.direction, shape->saved_ray.direction);
	*b = 2 * dot(shape->saved_ray.direction, to_ray);
	c = dot(to_ray, to_ray) - 1;
	return (*b * *b - 4 * *a * c);
}

t_intersection	intersection(double t, t_obj *shape)
{
	t_intersection	inter;

	inter.shape = shape;
	inter.t = t;
	return (inter);
}

t_inter	*intersections(int c, ...)
{
	va_list	intersects;
	int		i;
	t_inter	*inters;
	t_inter	*new;

	inters = NULL;
	va_start(intersects, c);
	i = 0;
	while (i < c)
	{
		new = new_inter_node(va_arg(intersects, t_intersection));
		add_inter_node(&inters, new);
		i++;
	}
	va_end(intersects);
	return (inters);
}

t_inter	*intersect(t_obj *shape)
{
	double	disc;
	double	a;
	double	b;
	t_inter	*i;

	disc = discriminant(shape, &a, &b);
	if (disc < 0)
		return (NULL);
	i = NULL;
	add_inter_node(&i,
		new_inter_node(intersection(
				(-b - sqrt(disc)) / (2 * a), shape)));
	add_inter_node(&i,
		new_inter_node(intersection(
				(-b + sqrt(disc)) / (2 * a), shape)));
	return (i);
}
