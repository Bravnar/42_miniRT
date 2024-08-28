/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:09:18 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/28 13:09:18 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "object.h"

typedef struct s_sphere
{
	t_obj	shape;
	double	diameter;
}	t_sphere;

t_sphere		*sphere_create(char **sphere_split, int i);
void			sphere_destroy(t_obj *shape);
t_sphere		*sphere(int i);
t_sphere		*glass_sphere(int i);
t_tup			local_normal_at_s(t_obj *sphere, t_tup point);
t_inter			*local_intersect_s(t_ray r, t_obj *sphere);
void			transform_s(t_obj *sphere, t_matrix transformation);
double			volume_s(t_obj *sphere);
char			*get_name_s(t_obj *sphere);

#endif
