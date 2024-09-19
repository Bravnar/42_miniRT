/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:57:08 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/19 18:23:10 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_name_s(t_obj *sphere)
{
	(void) sphere;
	return ("Sphere");
}

double	volume_s(t_obj *sphere)
{
	t_sphere	*sphere_1;
	double		radius;

	sphere_1 = (t_sphere *)sphere;
	radius = sphere_1->diameter / 2.0;
	return ((4.0 / 3.0) * PI * pow(radius, 3));
}

void	pat_mat_sp(char **sp_split, t_sphere *sp)
{
	t_pattern	pat;
	t_color		prim;
	t_color		sec;

	prim = color_split(sp_split[2], (void *) sp);
	if (!RT_BONUS)
	{
		pat = pat_default(prim);
		sp->shape.material = material(pat, 0.9, 0.9, 200);
		sp->shape.material.refractive_index = 0;
		sp->shape.material.reflective = 0;
		sp->shape.material.transparency = 0;
	}
	else
	{
		sec = color_split(sp_split[4], (void *) sp);
		pat = pattern(prim, sec, range_int(sp_split[3], 0, 3),
				matrix_mult(rotation_z(0), scaling_matrix(1, 1, 1)));
		sp->shape.material = material (pat, 0.9, 0.9, 200);
		sp->shape.material.refractive_index = range_double(
				sp_split[6], 0.0, 5.0, 0);
		sp->shape.material.reflective = range_double(sp_split[5], 0.0, 1.0, 0);
		sp->shape.material.transparency = range_double(sp_split[7], 0.0, 1.0, 0);
		sp->shape.material.pattern.scale = range_double(sp_split[8], 0, 20, 0);
	}
}

t_sphere	*sphere_create(char **sphere_split, int i)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere_set_up(sphere, i);
	sphere->diameter = ft_strtod(sphere_split[1], sphere_split);
	sphere->shape.point = str_to_point(sphere_split[0], (void *) sphere);
	sphere->shape.dir_vector = vector(0, 0, 0);
	pat_mat_sp(sphere_split, sphere);
	sphere->shape.transform((t_obj *) sphere,
		matrix_mult(translation_matrix(sphere->shape.point.x,
				sphere->shape.point.y, sphere->shape.point.z),
			scaling_matrix(sphere->diameter / 2,
				sphere->diameter / 2, sphere->diameter / 2)));
	return (sphere);
}

void	sphere_destroy(t_obj *shape)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)shape;
	free(sphere);
}
