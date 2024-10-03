/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:42:46 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 08:42:46 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Applies a transformation matrix to a cube shape.
 *
 * This function takes a cube shape object and a transformation matrix,
 * and applies the transformation to the cube.
 *
 * @param shape Pointer to the cube shape object to be transformed.
 * @param transformation The transformation matrix to be applied to the cube.
 */
void	transform_cu(t_obj *shape, t_matrix transformation)
{
	t_cube	*cube;

	cube = (t_cube *) shape;
	cube->shape.transformation = matrix_mult(cube->shape.transformation,
			transformation);
	cube->shape.transformation = matrix_mult(cube->shape.inverse_transformation,
			inverse(transformation, 4));
}

/**
 * @brief Computes the local intersection of a ray with a cube.
 *
 * This function calculates the intersection points of a given ray with a cube
 * object. It returns a list of intersection points (if any) where the ray
 * intersects the cube.
 *
 * @param r The ray to be tested for intersection with the cube.
 * @param cube The cube object to test for intersection.
 * @return A pointer to a list of intersection points (t_inter) where the ray
 *    intersects the cube. If there are no intersections, the list will be empty.
 */
t_inter	*local_intersect_cu(t_ray r, t_obj *cube)
{
	t_ray	inv_ray;

	inv_ray = ray_transform(r, cube->inverse_transformation);
	cube->saved_ray = inv_ray;
	return (intersect(cube));
}

/**
 * @brief Creates and initializes a new cube object.
 *
 * This function allocates memory for a new cube object and initializes its
 * properties. The cube object can then be used in various operations related
 * to 3D shapes.
 *
 * @return A pointer to the newly created cube object.
 */
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
