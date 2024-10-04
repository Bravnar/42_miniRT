/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:13:03 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:13:24 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Creates a translation matrix.
 *
 * This function generates a 4x4 matrix that represents a translation
 * transformation in 3D space. The translation is defined by the
 * displacement values along the x, y, and z axes.
 *
 * @param x The translation distance along the x-axis.
 * @param y The translation distance along the y-axis.
 * @param z The translation distance along the z-axis.
 * @return A 4x4 matrix representing the translation transformation.
 */
t_matrix	translation_matrix(double x, double y, double z)
{
	t_matrix	matrix;

	matrix = identity();
	matrix.m[0][3] = x;
	matrix.m[1][3] = y;
	matrix.m[2][3] = z;
	return (matrix);
}

/**
 * @brief Translates a point by given x, y, and z values.
 *
 * This function takes a point and translates it by the specified
 * x, y, and z values. The translation is applied to the point's
 * coordinates, effectively moving it in 3D space.
 *
 * @param point The point to be translated.
 * @param x The translation value along the x-axis.
 * @param y The translation value along the y-axis.
 * @param z The translation value along the z-axis.
 * @return The translated point.
 */
t_tup	translate(t_tup point, double x, double y, double z)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = translation_matrix(x, y, z);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}

/**
 * @brief Applies an inverse translation to a given point.
 *
 * This function takes a point and translates it by the negative of the given
 * x, y, and z values. It effectively moves the point in the opposite direction
 * of a standard translation.
 *
 * @param point The point to be translated.
 * @param x The x-coordinate translation value.
 * @param y The y-coordinate translation value.
 * @param z The z-coordinate translation value.
 * @return The translated point.
 */
t_tup	inverse_translate(t_tup point, double x, double y, double z)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = inverse(translation_matrix(x, y, z), 4);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}
