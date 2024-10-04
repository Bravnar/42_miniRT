/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:20:52 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:28:29 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Creates a new intersection structure.
 *
 * This function initializes a new intersection structure with the given count
 * and shape. Additional parameters can be passed using variadic arguments.
 *
 * @param count The number of intersections.
 * @param shape A pointer to the shape object involved in the intersection.
 * @param ... double numbers (values for intersections).
 * @return A pointer to the newly created intersection structure.
 */
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

/**
 * Calculates the discriminant for a given shape.
 *
 * @param shape A pointer to the shape object.
 * @param a A pointer to the coefficient 'a' of the quadratic equation.
 * @param b A pointer to the coefficient 'b' of the quadratic equation.
 * @return The discriminant value.
 */
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

/**
 * @brief Creates an intersection structure.
 *
 * This function initializes an intersection structure with the given
 * parameters. The intersection structure contains information about
 * the intersection point of a ray with a shape.
 *
 * @param t The distance from the ray origin to the intersection point.
 * @param shape A pointer to the shape that the ray intersects with.
 * @return A t_intersection structure containing the intersection information.
 */
t_intersection	intersection(double t, t_obj *shape)
{
	t_intersection	inter;

	inter.shape = shape;
	inter.t = t;
	return (inter);
}

/**
/**
 * @brief Implements the function to calculate intersections in raycasting.
 *
 * The intersections function is used to handle multiple intersection points.
 * It takes a variable number of arguments and processes them accordingly.
 *
 * @param c The number of intersection points.
 * @param ... A variable number of arguments t_intersection objects.
 *
 * @return A pointer to a t_inter structure containing the intersection data.
 */
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
