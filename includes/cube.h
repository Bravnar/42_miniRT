/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:02:58 by smuravye          #+#    #+#             */
/*   Updated: 2024/07/23 15:53:20 by smuravye         ###   ########.fr       */
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


#endif