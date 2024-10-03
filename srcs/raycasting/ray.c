/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:29:03 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:29:12 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Creates a new ray with a given origin point and direction.
 *
 * This function initializes a new ray structure with the specified origin
 * point and direction vector. The ray is used in raycasting operations to
 * determine intersections with objects in a scene.
 *
 * @param point The origin point of the ray.
 * @param direction The direction vector of the ray.
 * @return A new ray structure initialized with the given point and direction.
 */
t_ray	ray_new(t_tup point, t_tup direction)
{
	t_ray	ray;

	ray.point = point;
	ray.direction = direction;
	return (ray);
}

/**
 * Computes the position of a ray at a given parameter t.
 *
 * @param ray The ray for which the position is to be computed.
 * @param t The parameter at which the position is to be computed.
 * @return The position of the ray at parameter t.
 */
t_tup	position(t_ray ray, double t)
{
	t_tup	pos;

	pos = tuple_add(ray.point, scale(ray.direction, t, t, t));
	return (pos);
}
