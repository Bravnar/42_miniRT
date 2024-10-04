/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:56:09 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 08:56:23 by hmorand          ###   ########.ch       */
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

/**
 * @brief Parses material properties for a sphere from a split string array.
 *
 * This function takes a split string array containing sphere properties and
 * assigns the appropriate material properties to the given sphere structure.
 *
 * @param sp_split A double pointer to a character array containing the split
 *                 sphere properties.
 * @param sp       A pointer to the sphere structure to which the material
 *                 properties will be assigned.
 *
 * * Note: If RT_BONUS is equal to 1, the setup takes into account more complex
 * patterns as well as reflectiveness and refraction.
 */
void	pat_mat_sp(char **sp_split, t_sphere *sp)
{
	t_pattern	pat;
	t_color		prim;
	t_color		sec;

	prim = color_split(sp_split[2]);
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
		sec = color_split(sp_split[4]);
		pat = pattern(prim, sec, range_int(sp_split[3], 0, 3),
				matrix_mult(rotation_z(0), scaling_matrix(1, 1, 1)));
		sp->shape.material = material (pat, 0.9, 0.9, 200);
		sp->shape.material.refractive_index = range_double(
				sp_split[6], 0.0, 5.0);
		sp->shape.material.reflective = range_double(sp_split[5], 0.0, 1.0);
		sp->shape.material.transparency = range_double(sp_split[7], 0.0, 1.0);
		sp->shape.material.pattern.scale = range_double(sp_split[8], 0, 20);
	}
}

/**
 * @brief Creates a new sphere object from the given parameters.
 *
 * This function takes an array of strings representing the sphere's properties
 * and an index, and returns a pointer to a newly created sphere object.
 *
 * @param sphere_split An array of strings containing the sphere's properties.
 * @param i The index of the sphere in the array.
 * @return A pointer to the newly created sphere object.
 */
t_sphere	*sphere_create(char **sphere_split, int i)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere_set_up(sphere, i);
	sphere->diameter = ft_strtod(sphere_split[1]);
	sphere->shape.point = str_to_point(sphere_split[0]);
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
