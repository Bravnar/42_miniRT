/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 25/07/2024 09:40:36 by hmorand           #+#    #+#             */
/*   Updated: 25/07/2024 09:40:36 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	vector_mag(t_tup a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w));
}

bool	is_unit_vector(t_tup a)
{
	return (equal(vector_mag(a), 1.0));
}

double	vector_dot(t_tup a, t_tup b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}
