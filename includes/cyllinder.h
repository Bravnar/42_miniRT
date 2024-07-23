/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyllinder.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:03:18 by smuravye          #+#    #+#             */
/*   Updated: 2024/07/23 17:38:04 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLLINDER_H
# define CYLLINDER_H

# include "object.h"

typedef struct	s_cyl
{
	t_obj	shape;
	double	diameter;
	double	height;
}	t_cyl;

t_cyl	cyl_create(double diameter, double height);
void	cyl_destroy(t_obj	*shape);

#endif