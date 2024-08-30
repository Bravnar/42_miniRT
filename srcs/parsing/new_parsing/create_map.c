#include "main.h"

typedef enum e_type
{
	WINDOW,
	AMBIENT,
	CAMERA,
	LIGHTS,
	OBJECTS,
}	t_type;

t_file	parse_file(char *filename)
{
	t_file	file;

	file.fd = open(filename)
}

void	*search_file(t_file *file, t_type type)
{
	t_parse	*tmp;

	tmp = file->parse;
	while (tmp)
	{
		if (type == WINDOW)
			return (assign_window(tmp));
		if (type == AMBIENT)
			return (assign_ambient(tmp));
		if (type == CAMERA)
			return (assing_camera(tmp));
		if (type == LIGHTS)
			return (assign_lights(tmp));
		if (type == OBJECTS)
			return (assign_objects(tmp));
		tmp = tmp->next;
	}
	return (NULL);
}

t_map	*create_map(char *filename)
{
	static t_map	*map;

	if (map)
		return (map);
	if (!filename)
		return (NULL);
	map = ft_calloc(1, sizeof(t_map));
	map->file = parse_file(filename);
	map->win = search_file(map->file, WINDOW);
	map->amb = search_file(map->file, AMBIENT);
	map->cam = search_file(map->file, CAMERA);
	map->light = search_file(map->file, LIGHTS);
	map->obj_list = search_file(map->file, OBJECTS);
}

t_map	*get_map(void)
{
	static t_map	*map;

	if (!map)
		map = create_map(NULL);
	return (map);
}

t_mrt	*initialize(char *filename)
{
	t_mrt	*mrt;

	mrt = malloc(sizeof(t_mrt));
	if (!mrt)
		return (NULL);
	mrt->map = create_map(filename);
	init_mlx(&mrt->mlx);
	return mrt;
}