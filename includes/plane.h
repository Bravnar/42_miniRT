/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:36:33 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/26 13:36:33 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

#include "object.h"

typedef struct	s_plane
{
	t_obj	shape;
}	t_plane;

t_plane	*plane_create(void);
void	plane_destroy(t_obj *shape);

#endif
