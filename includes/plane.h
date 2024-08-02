/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:36:33 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/02 11:09:36 by smuravye         ###   ########.fr       */
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

#endif
