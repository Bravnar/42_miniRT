#include "main.h"

void	read_rt(char *filename, t_file *file)
{
	t_parse	*node;
	char	*line;

	file->fd = open(filename, O_RDONLY);
	if (file->fd == -1)
		err_handler(OPEN_FAILED);
	// line = get_next_line(file->fd);
	line = ft_strdup("");
	while (line)
	{
		free(line);
		line = get_next_line(file->fd);
		if (!ft_strcmp(line, "\n"))
			continue ;
		node = new_parse_node(line);
		add_node(&file->parse, node);
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

void	*extract_info(t_parse **head, t_type type)
{
	t_parse	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (type == WINDOW)
			return (handle_window(tmp));
		if (type == AMBIENT)
			return (handle_ambient(tmp));
		if (type == CAMERA)
			return (handle_camera(tmp));
		if (type == LIGHTS)
			return (handle_lights(&tmp));
		if (type == OBJECTS)
			return (handle_objs(&tmp));
		if (tmp->next)
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
	map->win = (t_rwin *)extract_info(&map->file.parse, WINDOW);
	map->amb = extract_info(&map->file.parse, AMBIENT);
	map->cam = extract_info(&map->file.parse, CAMERA);
	map->light = extract_info(&map->file.parse, LIGHTS);
	map->obj_list = extract_info(&map->file.parse, OBJECTS);
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
	t_mrt	*mrt;

	mrt = ft_calloc(1, sizeof(t_mrt));
	if (!mrt)
		return (NULL);
	mrt->map = create_map(filename);
	/* init_mlx(&mrt->mlx);  TEMPORARY COMMENT OUT*/
	return mrt;
}