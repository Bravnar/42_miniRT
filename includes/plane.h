/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:03:47 by smuravye          #+#    #+#             */
/*   Updated: 2024/07/24 10:19:18 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

#include "object.h"

typedef struct	s_plane
{
	t_obj	shape;
}	t_plane;

t_plane	plane_create(void);
void	plane_destroy(t_obj *shape);

#endif