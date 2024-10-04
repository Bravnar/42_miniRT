/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:57:01 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 14:57:01 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Generates a stripe pattern color based on the given point and pattern.
 *
 * This function calculates the color of a stripe pattern at a specific point
 * on a given shape. The pattern is defined by the `pat` parameter.
 *
 * @param shape A pointer to the object (shape) on which the pattern is applied.
 * @param point The point on the shape where the color is to be determined.
 * @param pat The pattern definition containing the colors and other properties.
 * @return The color at the specified point based on the stripe pattern.
 */
t_color	stripe_pattern(t_obj *shape, t_tup point, t_pattern pat)
{
	t_tup	object_point;
	t_tup	pattern_point;

	pat.transform(&pat, matrix_mult(scaling_matrix(0.2, 0.2, 0.2),
			rotation_z_pat(45, shape->get_name(shape))));
	object_point = matrix_mult_tup(shape->inverse_transformation, point);
	pattern_point = matrix_mult_tup(pat.inverse_transformation, object_point);
	if (equal(fmod(floor(pattern_point.x), 2), 0))
		return (pat.colors[0]);
	else
		return (pat.colors[1]);
}
