/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:42:03 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/19 13:42:07 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_name_pl(t_obj *shape)
{
	(void) shape;
	return ("Plane");
}

void	plane_set_up(t_plane *plane, int i)
{
	plane->shape.transformation = identity();
	plane->shape.inverse_transformation = identity();
	plane->shape.get_name = get_name_pl;
	plane->shape.volume = 0;
	plane->shape.destroy = plane_destroy;
	plane->shape.local_normal_at = local_normal_at_pl;
	plane->shape.transform = transform_pl;
	plane->shape.local_intersect = local_intersect_pl;
	plane->shape.next = NULL;
	plane->shape.id = i;
}

void	pat_mat_pl(char **p_split, t_plane *pl)
{
	t_pattern	pat;
	t_color		prim;
	t_color		sec;

	prim = color_split(p_split[2]);
	if (!RT_BONUS)
	{
		pat = pat_default(prim);
		pl->shape.material = material(pat, 0.9, 0.9, 200);
		pl->shape.material.refractive_index = 0;
		pl->shape.material.reflective = 0;
		pl->shape.material.transparency = 0;
	}
	else
	{
		sec = color_split(p_split[4]);
		pat = pattern(prim, sec, range_int(p_split[3], 0, 3),
				matrix_mult(rotation_z(0), scaling_matrix(1, 1, 1)));
		pl->shape.material = material (pat, 0.9, 0.9, 200);
		pl->shape.material.refractive_index = range_double(
				p_split[6], 0.0, 5.0, 0);
		pl->shape.material.reflective = range_double(p_split[5], 0.0, 1.0, 0);
		pl->shape.material.transparency = range_double(p_split[7], 0.0, 1.0, 0);
		pl->shape.material.pattern.scale = range_double(p_split[8], 0, 20, 0);
	}
}

t_plane	*plane_create(char **plane_line, int i)
{
	t_plane		*p;

	p = malloc(sizeof(t_plane));
	if (!p)
		return (NULL);
	plane_set_up(p, i);
	pat_mat_pl(plane_line, p);
	p->shape.point = str_to_point(plane_line[0], NULL);
	p->shape.dir_vector = vector_norm(str_to_vector(plane_line[1], NULL));
	p->shape.transform((t_obj *) p, translation_matrix(
			p->shape.point.x, p->shape.point.y, p->shape.point.z));
	return (p);
}

void	plane_destroy(t_obj *shape)
{
	t_plane	*plane;

	plane = (t_plane *)shape;
	free(plane);
}
