/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:39:12 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 08:40:22 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * Generates a shadow ray based on the given intersection computations
 * and direction. Adds an offset to the intersection
 * point to cancel shadow noise.
 *
 * @param comps The precomputed intersection computations.
 * @param direction The direction vector for the shadow ray.
 * @return A shadow ray originating from the
 * intersection point in the specified direction.
 */
t_ray	shadow_ray(t_comps comps, t_tup direction)
{
	t_tup	offset_point;

	offset_point = tuple_add(comps.over_point,
			vector_scalar_mult(direction, EPSILON));
	return (ray_new(offset_point, direction));
}

/**
 * @brief Calculates the shadow intensity at a given point in the world.
 *
 * This function determines how much shadow is present at a specific point
 * in the world by considering the light sources and objects that may block
 * the light. The shadow intensity is used to adjust the lighting and shading
 * of the point in the rendering process.
 *
 * @param world The world containing all objects and light sources.
 * @param point The point in the world where the
 * shadow intensity is to be calculated.
 * @return The shadow intensity at the given point,
 * typically a value between 0 and 1.
 */
double	calculate_shadow_intensity(t_world world, t_tup point)
{
	t_ray	shadow_ray;
	t_inter	*shadow_intersections;
	double	shadow_intensity;
	double	distance_to_light;
	t_inter	*current;

	shadow_ray = ray_new(point, light_vector(point));
	shadow_intersections = intersect_world(world, shadow_ray);
	shadow_intensity = 1.0;
	current = shadow_intersections;
	distance_to_light = vector_mag(tuple_sub(world.light->point, point));
	while (current != NULL && !equal(shadow_intensity, 0.0))
	{
		if (current->i.t > 0 && current->i.t < distance_to_light)
		{
			if (current->i.shape->material.transparency == 0)
				shadow_intensity = 0;
			else
				shadow_intensity *= current->i.shape->material.transparency;
		}
		current = current->next;
	}
	free_inter_nodes(shadow_intersections);
	return (shadow_intensity);
}

/**
 * @brief Determines if a point in the world is in shadow.
 *
 * This function checks if the point described by the intersection
 * computations (comps) is in shadow within the given world (w).
 *
 * @param w The world containing all objects and light sources.
 * @param comps The precomputed intersection data for a point.
 * @return true if the point is in shadow, false otherwise.
 */
bool	is_shadowed(t_world w, t_comps comps)
{
	t_tup			v;
	t_tup			direction;
	t_ray			shadow_r;
	t_inter			*inter;
	t_intersection	h;

	v = tuple_sub(w.light->point, comps.over_point);
	direction = vector_norm(v);
	shadow_r = shadow_ray(comps, direction);
	inter = intersect_world(w, shadow_r);
	h = hit(&inter);
	free_inter_nodes(inter);
	return (h.t != -1 && h.t < vector_mag(v));
}
	/* t_ray			shadow_ray;
	 if (h.shape)
	{
		shadow_ray = ray_new(
				tuple_add(comps.over_point, vector_scalar_mult(
						h.shape->local_normal_at(h.shape, comps.over_point),
						0.0001)), direction);
		free_inter_nodes(inter);
		inter = intersect_world(w, shadow_ray);
		h = hit(&inter);
	} */
