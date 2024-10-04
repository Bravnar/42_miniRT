/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:15:10 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:15:38 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Copies the given intersection structure.
 *
 * This function takes an intersection structure as input and returns
 * a copy of it.
 *
 * @param i The intersection structure to be copied.
 * @return A copy of the given intersection structure.
 */
t_intersection	copy_intersection(t_intersection i)
{
	t_intersection	new;

	new.t = i.t;
	new.shape = i.shape;
	return (new);
}

/**
 * @function hit
 * @brief Determines the closest intersection from a list of intersections.
 *
 * This function takes a list of intersections and returns the closest one.
 *
 * @param inters A pointer to an array of intersection pointers.
 * @return The closest intersection.
 */
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

/**
 * @brief Determines the nearest intersection from a list of intersections.
 *
 * This function takes an array of intersection pointers and returns the nearest
 * intersection among them.
 *
 * @param inters An array of pointers to intersections.
 * @return The nearest intersection.
 */
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
