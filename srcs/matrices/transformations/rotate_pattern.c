/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:08:37 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:08:37 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Rotates a pattern around the Z-axis by a given angle.
 *
 * This function generates a rotation matrix for rotating a pattern
 * around the Z-axis by the specified angle. The rotation is applied
 * to the pattern identified by the given name.
 *
 * @param angle The angle in radians by which to rotate the pattern.
 * @param name The name of the pattern to be rotated.
 * @return A rotation matrix representing the rotation around the Z-axis.
 */
t_matrix	rotation_z_pat(double angle, char *name)
{
	if (!ft_strcmp("sphere", name))
		return (matrix_mult(rotation_z(angle), rotation_y(-angle / 4 * 3)));
	if (!ft_strcmp("plane", name))
		return (matrix_mult(rotation_z(angle), rotation_y(+angle / 3 * 2)));
	return (matrix_mult(rotation_z(angle), rotation_y(+angle / 3 * 2)));
}
