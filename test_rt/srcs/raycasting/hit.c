/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:00:47 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/18 10:00:47 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_intersection	copy_intersection(t_intersection i)
{
	t_intersection	new;

	new.t = i.t;
	new.shape = i.shape;
	return (new);
}

t_intersection	hit(t_inter **inters)
{
	t_inter			*tmp;
	t_intersection	h;

	tmp = *inters;
	h = intersection(-1, NULL);
	if (inters == NULL)
		return (h);
	while (tmp)
	{
		if (tmp->i.t > 0)
			return (copy_intersection(tmp->i));
		tmp = tmp->next;
	}
	return (h);
}

t_intersection	nhit(t_inter **inters)
{
	t_inter			*tmp;
	t_intersection	h;

	tmp = *inters;
	h = intersection(-1, NULL);
	if (inters == NULL)
		return (h);
	while (tmp)
	{
		if (tmp->i.t > 0)
			return (copy_intersection(tmp->i));
		tmp = tmp->next;
	}
	return (h);
}
