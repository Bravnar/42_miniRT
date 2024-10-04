/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:11:56 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:12:47 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Applies a shearing transformation to a matrix.
 *
 * This function takes an array of six double values representing
 * the shearing factors and applies the shearing transformation to a matrix.
 *
 * @param numbers An array of six double values representing
 * 				  the shearing factors.
 *                The array should be in the following order:
 *                [xy, xz, yx, yz, zx, zy]
 *                where:
 *                - xy: Shear factor for x in the direction of y
 *                - xz: Shear factor for x in the direction of z
 *                - yx: Shear factor for y in the direction of x
 *                - yz: Shear factor for y in the direction of z
 *                - zx: Shear factor for z in the direction of x
 *                - zy: Shear factor for z in the direction of y
 *
 * @return A t_shear structure representing the shearing transformation.
 */
t_shear	shear(double numbers[6])
{
	t_shear	s;

	s.xy = numbers[0];
	s.xz = numbers[1];
	s.yx = numbers[2];
	s.yz = numbers[3];
	s.zx = numbers[4];
	s.zy = numbers[5];
	return (s);
}

/**
 * @brief Generates a shearing transformation matrix.
 *
 * This function takes a shearing structure as input and returns a matrix
 * that represents the shearing transformation. Shearing is a transformation
 * that displaces each point in a fixed direction, by an amount proportional
 * to its signed distance from a line that is parallel to that direction.
 *
 * @param sh A structure containing the shearing factors.
 * @return A matrix representing the shearing transformation.
 */
t_matrix	shearing_matrix(t_shear sh)
{
	t_matrix	matrix;

	matrix = identity();
	matrix.m[0][1] = sh.xy;
	matrix.m[0][2] = sh.xz;
	matrix.m[1][0] = sh.yx;
	matrix.m[1][2] = sh.yz;
	matrix.m[2][0] = sh.zx;
	matrix.m[2][1] = sh.zy;
	return (matrix);
}

/**
 * @brief Applies a shearing transformation to a given point.
 *
 * This function takes a point and a shearing transformation matrix and
 * returns the transformed point after applying the shearing transformation.
 *
 * @param point The original point to be transformed.
 * @param sh The shearing transformation matrix.
 * @return The transformed point after applying the shearing transformation.
 */
t_tup	shearing(t_tup point, t_shear sh)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = shearing_matrix(sh);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}

/**
 * @brief Applies the inverse shearing transformation to a given point.
 *
 * This function takes a point and a shearing transformation and applies the
 * inverse of the shearing transformation to the point.
 *
 * @param point The point to be transformed.
 * @param sh The shearing transformation parameters.
 * @return The transformed point after applying the inverse shearing.
 */
t_tup	inverse_shearing(t_tup point, t_shear sh)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = inverse(shearing_matrix(sh), 4);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}
