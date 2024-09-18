/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 31/07/2024 18:35:30 by hmorand           #+#    #+#             */
/*   Updated: 31/07/2024 18:35:30 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_ray	ray_transform(t_ray ray, t_matrix transform)
{
	t_ray	result;

	result.direction = matrix_mult_tup(transform, ray.direction);
	result.point = matrix_mult_tup(transform, ray.point);
	return (result);
}
