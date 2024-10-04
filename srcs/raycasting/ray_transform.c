/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:28:50 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:28:50 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Transforms a ray using the specified transformation matrix.
 *
 * This function takes a ray and a transformation matrix as inputs and returns
 * the transformed ray. The transformation matrix is applied to the ray's origin
 * and direction to produce the new ray.
 *
 * @param ray The original ray to be transformed.
 * @param transform The transformation matrix to be applied to the ray.
 * @return The transformed ray.
 */
t_ray	ray_transform(t_ray ray, t_matrix transform)
{
	t_ray	result;

	result.direction = matrix_mult_tup(transform, ray.direction);
	result.point = matrix_mult_tup(transform, ray.point);
	return (result);
}
