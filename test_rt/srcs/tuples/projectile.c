/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 25/07/2024 09:40:36 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:06:32 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_proj	proj_new(t_tup position, t_tup velocity)
{
	t_proj	new;

	new.position = position;
	if (!equal(vector_mag(velocity), 1.0))
		new.velocity = vector_norm(velocity);
	else
		new.velocity = velocity;
	return (new);
}
