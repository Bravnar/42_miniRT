/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:04:13 by smuravye          #+#    #+#             */
/*   Updated: 2024/07/24 10:19:57 by smuravye         ###   ########.fr       */
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

t_sphere	sphere_create(double diameter);
void		sphere_destroy(t_obj *shape);

#endif