/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 27/07/2024 10:48:56 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:06:42 by hmorand          ###   ########.ch       */
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
