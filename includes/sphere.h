/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:36:29 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/02 10:41:51 by smuravye         ###   ########.fr       */
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

t_sphere	*sphere_create(char **sphere_split);
void		sphere_destroy(t_obj *shape);

#endif
