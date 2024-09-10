/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:52:52 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/07 10:52:52 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "object.h"

typedef struct	s_cyl
{
	t_obj	shape;
	double	diameter;
	double	height;
	double	max;
	double	min;
	bool	closed;
}	t_cyl;

t_cyl	*cyl_create(char **cyl_line, int i);
void	cyl_destroy(t_obj *shape);
char	*get_name_cy(t_obj *shape);
double	volume_cy(t_obj *shape);
void	transform_cy(t_obj *shape, t_matrix transformation);
t_inter	*local_intersect_cy(t_ray r, t_obj *cyl);
t_cyl	*cylinder(int i);
void	intersect_caps(t_obj *obj, t_ray r, t_inter *inter);

#endif
