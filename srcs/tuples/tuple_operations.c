/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:06:49 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/18 10:06:49 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_tup	tuple_sub(t_tup a, t_tup b)
{
	return (tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w ^ b.w));
}

t_tup	tuple_add(t_tup a, t_tup b)
{
	return (tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w ^ b.w));
}

t_tup	tuple_neg(t_tup a)
{
	return (tuple(-a.x, -a.y, -a.z, -a.w));
}
