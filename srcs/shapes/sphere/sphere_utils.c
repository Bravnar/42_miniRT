/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:52:50 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 08:54:55 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Computes the intersection of a ray with a sphere.
 *
 * This function calculates the intersection points (if any) between a given ray
 * and a sphere object. It returns a list of intersection points. It relies
 * on the basic implementation of the intersect function unlike other shapes.
 *
 * @param r The ray to test for intersection with the sphere.
 * @param sphere The sphere object to test for intersection with the ray.
 * @return A pointer to a list of intersection points (t_inter) if intersections
 *         are found, or NULL if no intersections are found.
 */
t_inter	*local_intersect_s(t_ray r, t_obj *sphere)
{
	(void) r;
	return (intersect(sphere));
}

/**
 * Computes the normal vector at a given point on the surface of a sphere.
 *
 * @param sphere A pointer to the sphere object.
 * @param point The point on the surface of the sphere
 * where the normal is to be computed.
 * @return The normal vector at the given point on the sphere.
 */
t_tup	local_normal_at_s(t_obj *sphere, t_tup point)
{
	t_tup	normal;

	normal = normal_at(sphere, point);
	if (sphere->material.pattern.scale > 1)
		normal = perturb_normal(sphere, point, normal,
				sphere->material.pattern);
	return (normal);
}

/**
 * @brief Creates a new sphere object.
 *
 * This function initializes a new sphere object with the given parameter.
 *
 * @param i An integer parameter used as the ID of the object.
 * @return A pointer to the newly created sphere object.
 */
t_sphere	*sphere(int i)
{
	t_sphere	*s;

	s = malloc(sizeof(t_sphere));
	if (!s)
		return (NULL);
	sphere_set_up(s, i);
	s->diameter = 2;
	s->shape.point = point(0, 0, 0);
	s->shape.dir_vector = vector(0, 0, 0);
	s->shape.material = mat_default();
	s->shape.transform((t_obj *) s,
		scaling_matrix(s->diameter / 2, s->diameter / 2, s->diameter / 2));
	return (s);
}

/* t_sphere	*glass_sphere(int i)
{
	t_sphere	*s;

	s = malloc(sizeof(t_sphere));
	if (!s)
		return (NULL);
	sphere_set_up(s, i);
	s->diameter = 2;
	s->shape.point = point(0, 0, 0);
	s->shape.dir_vector = vector(0, 0, 0);
	s->shape.material = mat_default();
	s->shape.material.refractive_index = 1.5;
	s->shape.material.transparency = 1;
	s->shape.transform((t_obj *) s,
		scaling_matrix(s->diameter / 2, s->diameter / 2, s->diameter / 2));
	return (s);
} */

void	transform_s(t_obj *sphere, t_matrix transformation)
{
	sphere->transformation = matrix_mult(sphere->transformation,
			transformation);
	sphere->inverse_transformation = matrix_mult(sphere->inverse_transformation,
			inverse(transformation, 4));
}

/**
 * @brief Sets up the properties of a sphere.
 *
 * This function initializes or modifies the properties of a given sphere
 * based on the provided index.
 *
 * @param sphere A pointer to the sphere structure to be set up.
 * @param i An integer parameter used as the ID of the object.
 */
void	sphere_set_up(t_sphere *sphere, int i)
{
	sphere->shape.id = i;
	sphere->shape.get_name = get_name_s;
	sphere->shape.volume = volume_s;
	sphere->shape.destroy = sphere_destroy;
	sphere->shape.transform = transform_s;
	sphere->shape.local_intersect = local_intersect_s;
	sphere->shape.local_normal_at = local_normal_at_s;
	sphere->shape.next = NULL;
	sphere->shape.transformation = identity();
	sphere->shape.inverse_transformation = identity();
}
