/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:55:11 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 14:55:17 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Generates a gradient pattern color based on the given
 * shape, point, and pattern.
 *
 * @param shape A pointer to the object shape.
 * @param point The point at which the pattern is evaluated.
 * @param pat The pattern structure containing the gradient information.
 * @return The color resulting from the gradient pattern at the specified point.
 */
t_color	gradient_pattern(t_obj *shape, t_tup point, t_pattern pat)
{
	t_color	distance;
	double	fraction;
	double	range;
	t_tup	object_point;
	t_tup	pattern_point;

	pat.transform(&pat, rotation_z_pat(-10, shape->get_name(shape)));
	object_point = matrix_mult_tup(shape->inverse_transformation, point);
	pattern_point = matrix_mult_tup(pat.inverse_transformation, object_point);
	distance = color_sub(pat.colors[1], pat.colors[0]);
	range = 2.0;
	fraction = (pattern_point.x + range / 2.0) / range;
	if (fraction < 0)
		fraction = 0;
	if (fraction > 1)
		fraction = 1;
	if (fraction == 0 && pattern_point.x == 0)
		return (pat.colors[0]);
	else if (fraction == 0 && pattern_point.x == 1)
		return (pat.colors[1]);
	return (color_add(pat.colors[0], color_scalarmult(fraction, distance)));
}
