/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 07/09/2024 09:59:36 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:04:56 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
