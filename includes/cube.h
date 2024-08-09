/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:14:44 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/09 12:14:44 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "object.h"

typedef struct	s_cube
{
	t_obj		shape;
	double		length;
	double		height;
	double		width;
}	t_cube;

void	cube_destroy(t_obj *shape);
char	*get_name_cu(t_obj *shape);
double	volume_cu(t_obj *shape);
void	transform_cu(t_obj *shape, t_matrix transformation);
t_inter	local_intersect_cu(t_ray r, t_obj *cube);
void	cube_destroy(t_obj *shape);
t_cube	*cube_create(char **cube_line);
#endif
