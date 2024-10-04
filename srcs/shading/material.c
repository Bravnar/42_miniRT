/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:35:52 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 08:37:27 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Creates a material with the specified properties.
 *
 * @param p The pattern of the material.
 * @param d The diffuse reflection coefficient.
 * @param s The specular reflection coefficient.
 * @param sh The shininess coefficient.
 * @return A t_material structure initialized with the given properties.
 */
t_material	material(t_pattern p, double d, double s, double sh)
{
	t_material	new_mat;

	new_mat.amb = get_map()->amb.ratio;
	new_mat.diffuse = d;
	new_mat.specular = s;
	new_mat.shininess = sh;
	new_mat.pattern = p;
	new_mat.reflective = 0;
	new_mat.refractive_index = 1.0;
	new_mat.transparency = 0;
	return (new_mat);
}

/**
 * @brief Creates and returns a default material.
 *
 * This function initializes a material structure with default values.
 * The default material can be used as a base for further customization
 * or as a placeholder in rendering calculations.
 *
 * @return A t_material structure initialized with default values.
 */
t_material	mat_default(void)
{
	t_material	new_mat;

	new_mat.amb = 0.1;
	new_mat.diffuse = 0.9;
	new_mat.specular = 0.9;
	new_mat.pattern = pattern(color(255, 255, 255), white(), PLAIN, identity());
	new_mat.shininess = 200;
	new_mat.reflective = 0.0;
	new_mat.refractive_index = 1.0;
	new_mat.transparency = 0;
	return (new_mat);
}
