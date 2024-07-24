/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:02:58 by smuravye          #+#    #+#             */
/*   Updated: 2024/07/24 10:20:42 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "object.h"

typedef struct	s_cube
{
	t_obj	shape;
	double	length;
	double	height;
	double	width;
}	t_cube;

t_cube	cube_create(double length, double height, double width);
void	cube_destroy(t_obj *shape);

#endif