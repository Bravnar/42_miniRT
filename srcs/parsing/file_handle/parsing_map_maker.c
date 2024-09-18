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
	map->win = fetch_res(&map->file.parse);
	map->amb = fetch_amb(&map->file.parse);
	map->cam = fetch_cam(&map->file.parse, map->win);
	map->light = fetch_light(&map->file.parse);
	map->obj_list = fetch_objs(&map->file.parse);
	return (map);
}

t_map	*get_map(void)
{
	static t_map	*map;

	if (!map)
		map = create_map(NULL);
	return (map);
}
