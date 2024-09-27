/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 17/09/2024 20:10:02 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:03:26 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_ray	shadow_ray(t_comps comps, t_tup direction)
{
	t_tup	offset_point;

	offset_point = tuple_add(comps.over_point,
			vector_scalar_mult(direction, EPSILON));
	return (ray_new(offset_point, direction));
}

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
