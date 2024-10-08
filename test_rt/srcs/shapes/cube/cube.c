/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 17/09/2024 20:10:02 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 09:56:54 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_name_cu(t_obj *shape)
{
	(void) shape;
	return ("Cube");
}

double	volume_cu(t_obj *shape)
{
	t_cube	*cube;

	cube = (t_cube *)shape;
	return (cube->length * cube->width * cube->height);
}

t_cube	*cube_create(char **cube_line, int i)
{
	t_cube		*c;
	t_pattern	pat;

	c = malloc(sizeof(t_cube));
	if (!c)
		return (NULL);
	c->length = ft_strtod(cube_line[2]);
	c->width = ft_strtod(cube_line[3]);
	c->height = ft_strtod(cube_line[4]);
	c->shape.get_name = get_name_cu;
	c->shape.volume = volume_cu;
	c->shape.destroy = cube_destroy;
	c->shape.transform = transform_cu;
	c->shape.local_intersect = local_intersect_cu;
	pat = pattern(color_split(cube_line[5]), white(), PLAIN, identity());
	c->shape.material = material(pat, 0.9, 0.9, 200);
	c->shape.point = str_to_point(cube_line[0]);
	c->shape.dir_vector = str_to_vector(cube_line[1]);
	c->shape.transformation = identity();
	c->shape.inverse_transformation = identity();
	c->shape.next = NULL;
	c->shape.id = i;
	return (c);
}

void	cube_destroy(t_obj *shape)
{
	t_cube	*cube;

	cube = (t_cube *)shape;
	free(cube);
}
