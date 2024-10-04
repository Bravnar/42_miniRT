/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:47:34 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 08:48:59 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Computes the intersection of a ray with a plane.
 *
 * This function calculates the intersection points (if any) between a given ray
 * and a plane object. It returns a pointer to a structure
 * containing the intersection details.
 *
 * @param r The ray to intersect with the plane.
 * @param plane The plane object to intersect with the ray.
 * @return A pointer to a t_inter structure containing the intersection details,
 *         or NULL if there is no intersection.
 */
t_inter	*local_intersect_pl(t_ray r, t_obj *plane)
{
	t_tup	to_orig;
	double	dot_prod;
	double	t;
	t_inter	*inter;

	dot_prod = dot(plane->local_normal_at(plane,
				plane->saved_ray.point), plane->saved_ray.direction);
	inter = NULL;
	if (!equal(dot_prod, 0))
	{
		to_orig = tuple_sub(plane->point, plane->saved_ray.point);
		t = dot(to_orig, plane->local_normal_at(plane, r.point)) / dot_prod;
		if (t >= 0)
			inter = new_inter_node(intersection(t, plane));
	}
	if (!inter)
		return (NULL);
	return (inter);
}

/**
 * Computes the local normal vector at a given point on a plane.
 *
 * @param plane A pointer to the plane object.
 * @param point The point at which to compute the normal vector.
 * @return The normal vector at the given point on the plane.
 */
t_tup	local_normal_at_pl(t_obj *plane, t_tup point)
{
	t_tup	normal;

	normal = vector_norm(
			matrix_mult_tup(plane->transformation, plane->dir_vector));
	if (plane->material.pattern.scale)
		normal = perturb_normal(plane, point, normal,
				plane->material.pattern);
	return (normal);
}

/**
 * @brief Creates and initializes a new plane object.
 *
 * This function allocates memory for a new plane object and initializes it
 * with the ID of the object. The integer parameter can be used to set
 * specific properties or attributes of the plane.
 *
 * @param i An integer used as the ID of the objects..
 * @return A pointer to the newly created plane object.
 */
t_plane	*plane(int i)
{
	t_plane	*p;

	p = malloc(sizeof(t_plane));
	if (!p)
		return (NULL);
	p->shape.get_name = get_name_pl;
	p->shape.volume = 0;
	p->shape.destroy = plane_destroy;
	p->shape.local_normal_at = local_normal_at_pl;
	p->shape.transform = transform_pl;
	p->shape.local_intersect = local_intersect_pl;
	p->shape.point = point(0, 0, 0);
	p->shape.dir_vector = vector(0, 1, 0);
	p->shape.material = mat_default();
	p->shape.transformation = identity();
	p->shape.id = i;
	p->shape.inverse_transformation = identity();
	p->shape.next = NULL;
	return (p);
}

void	transform_pl(t_obj *shape, t_matrix transformation)
{
	t_plane	*plane;

	plane = (t_plane *) shape;
	plane->shape.transformation = matrix_mult(plane->shape.transformation,
			transformation);
	plane->shape.transformation = matrix_mult(
			plane->shape.inverse_transformation,
			inverse(transformation, 4));
}
