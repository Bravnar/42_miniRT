/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 17/09/2024 20:10:02 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 09:45:46 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_name_cy(t_obj *shape)
{
	(void) shape;
	return ("Cylinder");
}

double	volume_cy(t_obj *shape)
{
	t_cyl		*cyl;
	double		radius;

	cyl = (t_cyl *)shape;
	radius = cyl->diameter / 2.0;
	return ((PI * pow(radius, 2)) * cyl->height);
}

void	cyl_set_up(t_cyl *cyl, int i)
{
	cyl->shape.get_name = get_name_cy;
	cyl->shape.volume = volume_cy;
	cyl->shape.destroy = cyl_destroy;
	cyl->shape.transform = transform_cy;
	cyl->shape.local_intersect = local_intersect_cy;
	cyl->shape.local_normal_at = local_normal_at_cy;
	cyl->shape.transformation = identity();
	cyl->shape.inverse_transformation = identity();
	cyl->shape.id = i;
	cyl->closed = true;
	cyl->shape.next = NULL;
}

t_cyl	*cyl_create(char **cyl_line, int i)
{
	t_cyl		*cyl;
	t_matrix	cyl_transform;

	cyl = malloc(sizeof(t_cyl));
	if (!cyl)
		return (NULL);
	cyl_set_up(cyl, i);
	cyl->diameter = ft_strtod(cyl_line[2]);
	cyl->height = ft_strtod(cyl_line[3]);
	cyl->max = cyl->height / 2;
	cyl->min = -cyl->height / 2;
	cyl->shape.point = str_to_point(cyl_line[0]);
	cyl->shape.dir_vector = str_to_vector(cyl_line[1]);
	cyl_transform = apply_transformation_cy(cyl);
	pat_mat_cy(cyl_line, cyl);
	cyl->shape.transform((t_obj *) cyl, cyl_transform);
	return (cyl);
}

void	cyl_destroy(t_obj *shape)
{
	t_cyl	*cyl;

	cyl = (t_cyl *)shape;
	free(cyl);
}
