/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:05:09 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/18 10:05:09 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_color	compute_eff_color(t_obj *shape, t_tup p)
{
	t_color	eff_color;
	t_color	intensity;

	intensity = get_map()->light->intensity;
	eff_color = color_product(
			shape->material.pattern.color_at(shape,
				p, shape->material.pattern), intensity);
	return (eff_color);
}

t_tup	light_vector(t_tup point)
{
	return (vector_norm(tuple_sub(get_map()->light->point, point)));
}

t_color	lighting(t_obj *shape, t_tup p, t_tup views[2], double shadow_intensity)
{
	t_color	eff_color;
	t_color	diff;
	t_color	spec;
	t_tup	v[3];
	double	light_dot_normal;

	eff_color = compute_eff_color(shape, p);
	v[0] = light_vector(p);
	v[1] = views[0];
	if (!shape->material.pattern.noise)
		v[2] = views[1];
	else
		v[2] = perturb_normal(shape, p, views[1], shape->material.pattern);
	light_dot_normal = dot(v[0], views[1]);
	diff = diffuse(light_dot_normal, shape->material, eff_color);
	spec = specular(light_dot_normal, shape->material, v);
	diff = color_scalarmult(shadow_intensity, diff);
	spec = color_scalarmult(shadow_intensity, spec);
	return (color_add(ambient(eff_color, shape->material),
			color_add(diff, spec)));
}
