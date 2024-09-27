/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_maker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:46:07 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/20 08:24:19 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_map	*create_map(char *filename)
{
	static t_map	*map;

	if (map)
		return (map);
	if (!filename)
		return (NULL);
	map = ft_calloc(1, sizeof(t_map));
	map->file = parse_file(filename);
	return (map);
}

void	fill_map(void)
{
	t_map	*map;

	map = get_map();
	map->win = fetch_res(&map->file.parse);
	map->amb = fetch_amb(&map->file.parse);
	map->cam = fetch_cam(&map->file.parse, map->win);
	map->light = fetch_light(&map->file.parse);
	map->obj_list = fetch_objs(&map->file.parse);
}

t_map	*get_map(void)
{
	static t_map	*map;

	if (!map)
		map = create_map(NULL);
	return (map);
}
