/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetching_lights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:57:22 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/19 15:57:22 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_light	*new_light_node(t_tup point, double bright, t_color rgb, t_color i)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return (NULL);
	light->point = point;
	light->bright = bright;
	light->rgb = rgb;
	light->intensity = i;
	light->next = NULL;
	return (light);
}

void	add_light_node(t_light **head, t_light *new_node)
{
	t_light	*tmp;

	if (!*head)
		*head = new_node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void	free_light_nodes(t_light *light)
{
	t_light	*tmp;

	if (!light)
		return ;
	while (light)
	{
		tmp = light;
		light = light->next;
		free(tmp);
	}
	tmp = NULL;
}

t_light	*fetch_light(t_parse **head)
{
	t_light	*l_head;
	t_parse	*tmp;
	t_light	*node;
	t_color	rgb;
	double	bright;

	tmp = *head;
	l_head = NULL;
	while (tmp)
	{
		if (tmp->type == LIGHTS)
		{
			bright = range_double(tmp->line_split[1], 0, 1);
			if (RT_BONUS)
				rgb = color_split(tmp->line_split[2]);
			else
				rgb = white();
			node = new_light_node(str_to_point(tmp->line_split[0]),
					bright, rgb,
					color_scalarmult(bright, rgb));
			add_light_node(&l_head, node);
		}
		tmp = tmp->next;
	}
	return (l_head);
}
