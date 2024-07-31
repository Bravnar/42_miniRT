/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:49:51 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/29 14:49:51 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "object.h"

typedef struct	s_cyl
{
	t_obj	shape;
	double	diameter;
	double	height;
}	t_cyl;

t_cyl	*cyl_create(double diameter, double height);
void	cyl_destroy(t_obj *shape);

#endif
