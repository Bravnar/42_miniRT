/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 30/08/2024 13:47:24 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:35:59 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_color	plain_pattern(t_obj *shape, t_tup point, t_pattern pat)
{
	(void) point;
	(void) shape;
	return (pat.colors[0]);
}
