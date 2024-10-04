/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:57:15 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 14:57:15 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Generates a plain color pattern for a given shape.
 *
 * This function returns a plain color pattern based on the provided shape,
 * point, and pattern information.
 *
 * @param shape A pointer to the object (shape) for which
 * the pattern is generated.
 * @param point The point at which the pattern is evaluated.
 * @param pat The pattern information used to generate the color.
 * @return The color resulting from the plain pattern.
 */
t_color	plain_pattern(t_obj *shape, t_tup point, t_pattern pat)
{
	(void) point;
	(void) shape;
	return (pat.colors[0]);
}
