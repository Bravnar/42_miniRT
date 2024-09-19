/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20/08/2024 08:15:18 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:04:45 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_tup	vector_reflect(t_tup in, t_tup normal)
{
	return (tuple_sub(in, vector_scalar_mult(normal, dot(in, normal) * 2)));
}
