/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:24:07 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/09 12:24:07 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

#include "object.h"

typedef struct	s_plane
{
	t_obj	shape;
}	t_plane;

t_plane	*plane_create(char **plane_line);
void	plane_destroy(t_obj *shape);
char	*get_name_pl(t_obj *shape);
void	transform_pl(t_obj *shape, t_matrix transformation);
t_inter	local_intersect_pl(t_ray r, t_obj *plane);
t_tup	local_normal_at_pl(t_obj *plane, t_tup point);
#endif
