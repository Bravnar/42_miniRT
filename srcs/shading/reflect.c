/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:42:24 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 08:42:24 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Reflects a vector around a given normal.
 *
 * This function calculates the reflection of an
 * incoming vector `in` around a given normal vector `normal`.
 *
 * @param in The incoming vector to be reflected.
 * @param normal The normal vector around which the reflection occurs.
 * @return The reflected vector.
 */
t_tup	vector_reflect(t_tup in, t_tup normal)
{
	return (tuple_sub(in, vector_scalar_mult(normal, dot(in, normal) * 2)));
}
