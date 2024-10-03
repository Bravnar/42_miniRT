/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:08:54 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:10:54 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Generates a rotation matrix for rotation around the x-axis.
 *
 * This function takes an angle in degrees and returns a 4x4 matrix that
 * represents a rotation around the x-axis by that angle.
 *
 * @param deg The angle in degrees by which to rotate around the x-axis.
 * @return A 4x4 matrix representing the rotation.
 */
t_matrix	rotation_x(double deg)
{
	t_matrix	matrix;
	double		rad;

	rad = deg / 180 * M_PI;
	matrix = identity();
	matrix.m[1][1] = cos(rad);
	matrix.m[1][2] = -sin(rad);
	matrix.m[2][1] = sin(rad);
	matrix.m[2][2] = cos(rad);
	return (matrix);
}

/**
 * @brief Creates a rotation matrix for a rotation around the Y-axis.
 *
 * This function generates a 4x4 matrix that represents a rotation by a given
 * angle around the Y-axis. The angle is specified in degrees.
 *
 * @param deg The angle in degrees by which to rotate around the Y-axis.
 * @return A 4x4 matrix representing the rotation.
 */
t_matrix	rotation_y(double deg)
{
	t_matrix	matrix;
	double		rad;

	rad = deg / 180 * M_PI;
	matrix = identity();
	matrix.m[0][0] = cos(rad);
	matrix.m[0][2] = sin(rad);
	matrix.m[2][0] = -sin(rad);
	matrix.m[2][2] = cos(rad);
	return (matrix);
}

/**
 * @brief Creates a rotation matrix for a rotation around the Z-axis.
 *
 * This function generates a 4x4 transformation matrix that represents a
 * rotation by a specified degree around the Z-axis. The rotation is
 * counterclockwise when looking from the positive Z-axis towards the origin.
 *
 * @param deg The angle of rotation in degrees.
 * @return A 4x4 matrix representing the rotation around the Z-axis.
 */
t_matrix	rotation_z(double deg)
{
	t_matrix	matrix;
	double		rad;

	rad = deg / 180 * M_PI;
	matrix = identity();
	matrix.m[0][0] = cos(rad);
	matrix.m[0][1] = -sin(rad);
	matrix.m[1][0] = sin(rad);
	matrix.m[1][1] = cos(rad);
	return (matrix);
}

/**
 * @brief Rotates a point around a specified axis by a given degree.
 *
 * This function takes a point and rotates it around the
 * specified axis (x, y, or z) by the given degree.
 * The rotation is performed using standard rotation matrices.
 *
 * @param point The point to be rotated, represented as a t_tup structure.
 * @param deg The degree by which to rotate the point.
 * @param axis The axis around which to rotate the point ('x', 'y', or 'z').
 * @return The rotated point as a t_tup structure.
 */
t_tup	rotate(t_tup point, double deg, char axis)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	if (axis == 'x')
		transformation_matrix = rotation_x(deg);
	else if (axis == 'y')
		transformation_matrix = rotation_y(deg);
	else
		transformation_matrix = rotation_z(deg);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}

/**
 * @brief Rotates a point in 3D space by a given degree
 * around a specified axis in the inverse direction.
 *
 * This function takes a point represented by a t_tup structure and
 * rotates it by the specified degree around the given axis
 * ('x', 'y', or 'z') in the inverse direction.
 *
 * @param point The point to be rotated, represented as a t_tup structure.
 * @param deg The degree by which to rotate the point.
 * @param axis The axis around which to rotate the point ('x', 'y', or 'z').
 * @return The rotated point as a t_tup structure.
 */
t_tup	inverse_rotate(t_tup point, double deg, char axis)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	if (axis == 'x')
		transformation_matrix = inverse(rotation_x(deg), 4);
	else if (axis == 'y')
		transformation_matrix = inverse(rotation_y(deg), 4);
	else
		transformation_matrix = inverse(rotation_z(deg), 4);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}
