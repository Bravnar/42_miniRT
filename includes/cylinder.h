/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:59:31 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/14 12:00:32 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "object.h"

typedef struct s_cyl
{
	t_obj	shape;
	double	diameter;
	double	height;
	double	max;
	double	min;
	bool	closed;
}	t_cyl;

t_cyl		*cyl_create(char **cyl_line, int i);
t_cyl		*cylinder(int i);
void		cyl_set_up(t_cyl *cyl, int i);
void		cyl_destroy(t_obj *shape);
char		*get_name_cy(t_obj *shape);
double		volume_cy(t_obj *shape);
t_inter		*local_intersect_cy(t_ray r, t_obj *cyl);
t_tup		local_normal_at_cy(t_obj *cyl, t_tup point);

/* CYLINDER SPECIFIC CALCULATIONS */

t_tup		calculate_rotations(t_tup dir_vector);
double		discriminant_cyl(t_obj *cyl, double *a, double *b);
t_matrix	apply_transformation_cy(t_cyl *cyl);
void		transform_cy(t_obj *shape, t_matrix transformation);
void		intersect_caps(t_obj *obj, t_ray r, t_inter *inter);

#endif
