/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:04:51 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/18 10:04:51 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_tup	normal_at(t_obj *shape, t_tup point)
{
	t_tup	object_point;
	t_tup	object_normal;
	t_tup	world_normal;

	object_point = matrix_mult_tup(shape->inverse_transformation, point);
	object_normal = tuple_sub(object_point, shape->point);
	world_normal = matrix_mult_tup(transpose(
				shape->inverse_transformation), object_normal);
	world_normal.w = 0;
	return (vector_norm(world_normal));
}
