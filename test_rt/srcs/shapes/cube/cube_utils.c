/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 17/09/2024 20:10:02 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 09:56:59 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	transform_cu(t_obj *shape, t_matrix transformation)
{
	t_cube	*cube;

	cube = (t_cube *) shape;
	cube->shape.transformation = matrix_mult(cube->shape.transformation,
			transformation);
	cube->shape.transformation = matrix_mult(cube->shape.inverse_transformation,
			inverse(transformation, 4));
}

t_inter	*local_intersect_cu(t_ray r, t_obj *cube)
{
	t_ray	inv_ray;

	inv_ray = ray_transform(r, cube->inverse_transformation);
	cube->saved_ray = inv_ray;
	return (intersect(cube));
}

t_cube	*cube(void)
{
	t_cube	*c;

	c = malloc(sizeof(t_cube));
	if (!c)
		return (NULL);
	c->length = 1;
	c->width = 1;
	c->height = 1;
	c->shape.get_name = get_name_cu;
	c->shape.volume = volume_cu;
	c->shape.destroy = cube_destroy;
	c->shape.transform = transform_cu;
	c->shape.local_intersect = local_intersect_cu;
	c->shape.material = mat_default();
	c->shape.point = point(0, 0, 0);
	c->shape.dir_vector = vector(0, 0, 1);
	c->shape.transformation = identity();
	c->shape.inverse_transformation = identity();
	c->shape.next = NULL;
	return (c);
}
