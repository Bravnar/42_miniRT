/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:58:40 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 08:58:40 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	vector_mag(t_tup a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w));
}

bool	is_unit_vector(t_tup a)
{
	return (equal(vector_mag(a), 1.0));
}

/**
 * @brief Computes the dot product of two vectors.
 *
 * This function takes two vectors (t_tup a and t_tup b)
 * and calculates their dot product.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The dot product of the two vectors.
 */
double	vector_dot(t_tup a, t_tup b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}
