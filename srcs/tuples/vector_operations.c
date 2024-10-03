/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:00:42 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 09:00:42 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_tup	vector_scalar_mult(t_tup a, double scalar)
{
	return (vector(a.x * scalar, a.y * scalar, a.z * scalar));
}

t_tup	vector_scalar_div(t_tup a, double scalar)
{
	return (vector(a.x / scalar, a.y / scalar, a.z / scalar));
}

t_tup	vector_norm(t_tup a)
{
	double	mag;

	mag = vector_mag(a);
	return (vector(a.x / mag, a.y / mag, a.z / mag));
}

/**
 * @brief Computes the cross product of two vectors.
 *
 * This function takes two vectors `a` and `b` as input
 * and returns their cross product.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The cross product of vectors `a` and `b`.
 */
t_tup	vector_cross(t_tup a, t_tup b)
{
	return (vector(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}

double	dot(t_tup a, t_tup b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}
