/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:33:43 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:33:43 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Computes the color reflected from a surface in the world.
 *
 * This function calculates the color that is reflected from a surface
 * based on the given world and the computed intersection components.
 * The remaining parameter indicates how many more reflections are allowed.
 *
 * @param world The world containing all objects and light sources.
 * @param comps The precomputed intersection components.
 * @param remaining The number of remaining reflections allowed.
 * @return The color resulting from the reflection.
 */
t_color	reflected_color(t_world world, t_comps comps, int remaining)
{
	t_ray	reflect_ray;
	t_color	color;

	if (comps.obj->material.reflective == 0 || remaining == 0)
		return (black());
	reflect_ray = ray_new(comps.over_point, comps.reflectv);
	color = iterative_color_at(world, reflect_ray, remaining - 1);
	return (color_scalarmult(comps.obj->material.reflective, color));
}

/* double	fresnel(t_comps comps)
{
	double n1 = 1.0; // Assume air for simplicity
	double n2 = comps.obj->material.refractive_index;
	double r0 = pow((n1 - n2) / (n1 + n2), 2);
	double cosX = dot(comps.eyev, comps.normalv);
	return r0 + (1 - r0) * pow(1 - cosX, 5);
}

t_color	reflected_color(t_world world, t_comps comps, int remaining)
{
	t_ray	reflect_ray;
	t_color	color;
	double	reflectance;

	color = black();
	if (comps.obj->material.reflective == 0 || remaining == 0)
		return (color);
	reflect_ray = ray_new(comps.over_point, comps.reflectv);
	reflectance = comps.obj->material.reflective;
	for (int i = 0; i < 5 && remaining > 0; i++)
	{
		color = color_add(color, color_scalarmult(reflectance,
				color_at(world, reflect_ray, remaining - 1)));
		remaining--;
		reflectance *= comps.obj->material.reflective;
	}
	return color;
} */
