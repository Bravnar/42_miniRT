/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:37:40 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:37:40 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_color	ambient(t_color effective_color, t_material mat)
{
	return (color_scalarmult(mat.amb, effective_color));
}

t_color	diffuse(double ldn, t_material m, t_color eff_color)
{
	if (ldn < 0)
		return (black());
	return (color_scalarmult(m.diffuse * ldn, eff_color));
}

/**
 * Computes the specular component of the lighting model.
 *
 * @param ldn The dot product of the light direction and the normal vector.
 * @param m The material properties of the surface.
 * @param v An array of three t_tup vectors:
 *          - v[0]: The light direction vector.
 *          - v[1]: The view direction vector.
 *          - v[2]: The normal vector at the point of intersection.
 * @return The color resulting from the specular reflection.
 */
t_color	specular(double ldn, t_material m, t_tup v[3])
{
	t_tup	reflect_v;
	t_color	intensity;
	double	factor;
	double	reflect_dot_eye;

	intensity = get_map()->light->intensity;
	if (ldn < 0)
		return (black());
	else
	{
		reflect_v = vector_reflect(tuple_neg(v[0]), v[2]);
		reflect_dot_eye = dot(reflect_v, v[1]);
		if (reflect_dot_eye <= 0)
			return (black());
		else
		{
			factor = pow(reflect_dot_eye, m.shininess) * m.specular;
			return (color_scalarmult(factor, intensity));
		}
	}
}
