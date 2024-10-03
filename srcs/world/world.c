/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:01:13 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 09:02:30 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * Computes the color with reflections and refractions.
 *
 * @param comps The precomputed values for intersections.
 * @param s The surface color.
 * @param refl The reflection color.
 * @param refr The refraction color.
 * @return The resulting color after applying reflections and refractions.
 */
t_color	with_reflect(t_comps comps, t_color s, t_color refl, t_color refr)
{
	double	reflectance;
	double	blend_factor;

	if (comps.obj->material.reflective > 0
		&& comps.obj->material.transparency > 0)
	{
		reflectance = schlick(comps);
		return (color_add(s, color_add(
					color_scalarmult(reflectance, refl),
					color_scalarmult(1 - reflectance, refr))));
	}
	else
	{
		blend_factor = fmax(comps.obj->material.reflective,
				comps.obj->material.transparency);
		return (color_add(
				color_scalarmult(1 - blend_factor, s),
				color_scalarmult(blend_factor, color_add(refl, refr))));
	}
}

/**
 * @brief Computes the color at the point of intersection
 * using iterative shading.
 *
 * This function calculates the color at the point of
 * intersection by iteratively shading the hit point. It takes
 * into account the world, the computed intersection components,
 * and the remaining recursion depth for reflective and refractive rays.
 *
 * @param w The world containing all objects and light sources.
 * @param comps The precomputed intersection components.
 * @param remaining The remaining recursion depth for reflective
 * and refractive rays.
 * @return The color at the point of intersection.
 */
t_color	iterative_shade_hit(t_world w, t_comps comps, int remaining)
{
	t_tup	views[2];
	t_color	surface;
	t_color	reflected;
	t_color	refracted;
	double	shadow_intensity;

	views[0] = comps.eyev;
	views[1] = comps.normalv;
	shadow_intensity = calculate_shadow_intensity(w, comps.over_point);
	surface = lighting(comps.obj, comps.point, views, shadow_intensity);
	reflected = reflected_color(w, comps, remaining);
	refracted = refracted_color(w, comps, remaining);
	return (with_reflect(comps, surface, reflected, refracted));
}

/**
 * @brief Computes the color at a given point in the world by tracing the ray.
 *
 * This function iteratively calculates the color at the intersection point
 * of the ray with objects in the world. It takes into account the remaining
 * number of reflections or refractions to be processed.
 *
 * @param w The world containing the objects and lights.
 * @param r The ray being traced.
 * @param remaining The number of remaining reflections or
 * refractions to be processed.
 * @return The color at the intersection point of the ray with the world.
 */
t_color	iterative_color_at(t_world w, t_ray r, int remaining)
{
	t_inter			*inters;
	t_intersection	h;
	t_comps			comps;
	t_color			color;

	inters = intersect_world(w, r);
	h = hit(&inters);
	if (h.t == -1)
	{
		free_inter_nodes(inters);
		return (black());
	}
	comps = prepare_comp(h, r, inters);
	free_inter_nodes(inters);
	color = iterative_shade_hit(w, comps, remaining);
	return (color);
}
	/* if (!RT_BONUS)
		color = iterative_shade_hit(w, comps, remaining);
	else
		color = iterative_shade_hit_multi(w, comps, remaining); */

/**
 * @brief Intersects a ray with the objects in the world.
 *
 * This function takes a world and a ray as input and returns the intersections
 * of the ray with the objects in the world.
 *
 * @param w The world containing the objects to intersect with.
 * @param r The ray to intersect with the objects in the world.
 * @return A pointer to the intersections of
 * the ray with the objects in the world.
 */
t_inter	*intersect_world(t_world w, t_ray r)
{
	t_obj	*tmp;
	t_inter	*xs;
	t_inter	*obj_tmp;

	xs = NULL;
	tmp = w.shapes;
	obj_tmp = NULL;
	while (tmp)
	{
		tmp->saved_ray = ray_transform(r, tmp->inverse_transformation);
		obj_tmp = tmp->local_intersect(r, tmp);
		if (!obj_tmp)
		{
			tmp = tmp->next;
			continue ;
		}
		add_inter_nodes(&xs, &obj_tmp);
		free_inter_nodes(obj_tmp);
		tmp = tmp->next;
	}
	return (xs);
}

/**
 * @brief Prepares the computation of intersection details.
 *
 * This function takes an intersection, a ray, and a list of intersections,
 * and prepares the necessary computations for shading and other operations.
 *
 * @param h The intersection to be processed.
 * @param r The ray that caused the intersection.
 * @param xs The list of all intersections.
 * @return A structure containing the computed details of the intersection.
 */
t_comps	prepare_comp(t_intersection h, t_ray r, t_inter *xs)
{
	t_comps	new;

	ft_bzero(&new, sizeof(t_comps));
	new.t = h.t;
	new.obj = h.shape;
	new.point = position(r, new.t);
	new.eyev = tuple_neg(r.direction);
	new.normalv = new.obj->local_normal_at(new.obj, new.point);
	new.reflectv = vector_reflect(r.direction, new.normalv);
	if (dot(new.normalv, new.eyev) < 0)
	{
		new.is_inside = true;
		new.normalv = tuple_neg(new.normalv);
	}
	else
		new.is_inside = false;
	new.over_point = tuple_add(new.point,
			vector_scalar_mult(new.normalv, EPSILON));
	new.under_point = tuple_sub(new.point,
			vector_scalar_mult(new.normalv, EPSILON));
	set_n1_n2(&new, h, &xs);
	return (new);
}

/* t_color shade_hit(t_world w, t_comps comps, int remaining)
{
	t_tup views[2];
	t_color reflected;
	t_color refracted;
	t_color surface;
	bool shadowed;

	views[0] = comps.eyev;
	views[1] = comps.normalv;
	shadowed = is_shadowed(w, comps);
	surface = lighting(comps.obj, comps.point, views, shadowed);
	reflected = reflected_color(w, comps, remaining);
	refracted = refracted_color(w, comps, remaining);
	return (with_reflect(comps, surface, reflected, refracted));
}

t_color	color_at(t_world w, t_ray r, int remaining)
{
	t_inter			*inters;
	t_intersection	h;
	t_comps			comps;

	inters = intersect_world(w, r);
	h = hit(&inters);
	if (h.t == -1)
		return (black());
	comps = prepare_comp(h, r, inters);
	free_inter_nodes(inters);
	return (shade_hit(w, comps, remaining));
} */
