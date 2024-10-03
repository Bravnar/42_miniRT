/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:41:52 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 08:42:18 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Computes the normal vector at a given point on the surface of a shape.
 *
 * This function calculates the normal vector at a specified point on the surface
 * of the given shape. The normal vector is essential for shading calculations
 * and determining how light interacts with the surface.
 *
 * @param shape A pointer to the shape object for which
 * 				the normal is being calculated.
 * @param point The point on the surface of the shape
 * 				where the normal is to be computed.
 * @return A t_tup structure representing the
 * 			normal vector at the specified point.
 */
t_tup	normal_at(t_obj *shape, t_tup point)
{
	t_tup	object_point;
	t_tup	object_normal;
	t_tup	world_normal;

	object_point = matrix_mult_tup(shape->inverse_transformation, point);
	object_normal = tuple_sub(object_point, shape->point);
	world_normal = matrix_mult_tup(transpose(
				shape->inverse_transformation), object_normal);
	world_normal.w = 0;
	return (vector_norm(world_normal));
}
