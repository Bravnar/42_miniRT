/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:01:17 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/18 10:01:22 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_ray	ray_new(t_tup point, t_tup direction)
{
	t_ray	ray;

	ray.point = point;
	ray.direction = direction;
	return (ray);
}

t_tup	position(t_ray ray, double t)
{
	t_tup	pos;

	pos = tuple_add(ray.point, scale(ray.direction, t, t, t));
	return (pos);
}
