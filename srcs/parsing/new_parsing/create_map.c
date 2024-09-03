#include "main.h"

void	read_rt(char *filename, t_file *file)
{
	t_parse	*node;
	char	*line;

	file->fd = open(filename, O_RDONLY);
	if (file->fd == -1)
		err_handler(OPEN_FAILED);
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

void	check_params(t_file *file)
{
	t_parse *tmp;

	tmp = file->parse;
	while (tmp)
	{
		printf("checking: %s\n", tmp->id);
		if (tmp->type == WINDOW && tmp->count != 2)
			err_handler(R_OVER_PARAM);
		else if (tmp->type == AMBIENT && tmp->count != 2)
			err_handler(A_OVER_PARAM);
		else if (tmp->type == CAMERA && tmp->count != 3)
			err_handler(C_OVER_PARAM);
		else if (tmp->type == LIGHTS && tmp->count != 3)
			err_handler(L_OVER_PARAM);
		// else if (tmp->type == OBJECTS)
		// 	check_obj_params();
		tmp = tmp->next;
	}
}

t_file	parse_file(char *filename)
{
	t_file	file;

	file.fd = -1;
	file.parse = NULL;
	if (!check_file_name(filename))
		err_handler(WRONG_EXT);
	ft_bzero(&file.count, sizeof(t_count));
	read_rt(filename, &file);
	check_count(&file);
	check_params(&file);
	return (file);
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