/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:11:19 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:11:29 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Creates a scaling transformation matrix.
 *
 * This function generates a 4x4 matrix that scales objects in 3D space
 * by the factors provided for the x, y, and z axes.
 *
 * @param x The scaling factor along the x-axis.
 * @param y The scaling factor along the y-axis.
 * @param z The scaling factor along the z-axis.
 * @return A 4x4 matrix representing the scaling transformation.
 */
t_matrix	scaling_matrix(double x, double y, double z)
{
	t_matrix	matrix;

	matrix = identity();
	matrix.m[0][0] = x;
	matrix.m[1][1] = y;
	matrix.m[2][2] = z;
	return (matrix);
}

/**
 * Scales a point by the given x, y, and z factors.
 *
 * @param point The point to be scaled.
 * @param x The scaling factor along the x-axis.
 * @param y The scaling factor along the y-axis.
 * @param z The scaling factor along the z-axis.
 * @return The scaled point.
 */
t_tup	scale(t_tup point, double x, double y, double z)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = scaling_matrix(x, y, z);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}

t_tup	inverse_scale(t_tup point, double x, double y, double z)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = inverse(scaling_matrix(x, y, z), 4);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}
