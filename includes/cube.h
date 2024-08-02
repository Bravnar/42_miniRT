/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:49:58 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/02 11:13:44 by smuravye         ###   ########.fr       */
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

t_cube	*cube_create(char **cube_line);
void	cube_destroy(t_obj *shape);

#endif
