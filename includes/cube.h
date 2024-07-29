/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:49:58 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/29 14:49:58 by hmorand          ###   ########.ch       */
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

t_cube	*cube_create(double length, double height, double width);
void	cube_destroy(t_obj *shape);

#endif
