#include "main.h"

void	read_rt(char *filename, t_file *file)
{
	t_parse	*node;
	char	*line;

	file->fd = open(filename, O_RDONLY);
	if (file->fd == -1)
		err_handler(OPEN_FAILED);
	line = get_next_line(file->fd);
	while (line)
	{
		node = new_parse_node(line);
		add_node(&file->parse, node);
		free(line);
		line = get_next_line(file->fd);
	}
	free(line);
}

t_file	parse_file(char *filename)
{
	t_file	file;

	file.fd = -1;
	file.parse = NULL;
	if (!check_file_name(filename))
		err_handler(WRONG_EXT);
	read_rt(filename, &file);



	return (file);
}

/* void	*search_file(t_file *file, t_type type)
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
} */

t_map	*create_map(char *filename)
{
	static t_map	*map;

	if (map)
		return (map);
	if (!filename)
		return (NULL);
	map = ft_calloc(1, sizeof(t_map));
	map->file = parse_file(filename);
	// map->win = search_file(map->file, WINDOW);
	// map->amb = search_file(map->file, AMBIENT);
	// map->cam = search_file(map->file, CAMERA);
	// map->light = search_file(map->file, LIGHTS);
	// map->obj_list = search_file(map->file, OBJECTS);
	return (map);
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
	printf("Entering initialize() ---------------:\n");
	t_mrt	*mrt;

	mrt = ft_calloc(1, sizeof(t_mrt));
	if (!mrt)
		return (NULL);
	mrt->map = create_map(filename);
	/* init_mlx(&mrt->mlx);  TEMPORARY COMMENT OUT*/

	printf("Exiting initialize() ----------------:\n");
	return mrt;
}