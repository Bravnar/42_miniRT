#include "main.h"

void	read_file(char *file_name, t_map *data)
{
	t_parse	*node;
	char	*line;

	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd == -1)
		err_handler(OPEN_FAILED);
	line = get_next_line(data->file.fd);
	while (line)
	{
		node = new_parse_node(line);
		add_node(&data->file.parse, node);
		free(line);
		line = get_next_line(data->file.fd);
	}
	free(line);
}

void	check_identifier(char *identifier)
{
	if (ft_strisalpha(identifier))
	{
		if (!ft_strstr(GOOD_ID, identifier))
		{
			printf(BOLD_WHITE" ---> %s\n"RESET, identifier);
			err_handler(UKNOWN_ID);
		}
	}
	else
	{
		printf(BOLD_WHITE" ---> %s\n"RESET, identifier);
		err_handler(UKNOWN_ID);
	}
}

/* void	check_identifier(t_parse **head)
{
	t_parse	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->line_split && tmp->line_split[0])
		{
			if (ft_strisalpha(tmp->line_split[0]))
			{
				if (!ft_strstr(GOOD_ID, tmp->line_split[0]))
					err_handler(UKNOWN_ID);
			}
			else
				err_handler(UKNOWN_ID);
		}
		tmp = tmp->next;
	}
} */

int	check_file_name(char *name)
{
	size_t	length;
	char	*tested_string;

	length = ft_strlen(name);
	tested_string = ft_strstr(name + length - 3, ".rt");
	if (ft_strlen(tested_string) > 3)
		return (0);
	if (!tested_string)
		return (0);
	return (1);
}

void	populate_scene_struct(char *file_name, t_map *scene)
{
	if (!check_file_name(file_name))
		err_handler(WRONG_EXT);
	read_file(file_name, scene);
	check_count();
	populate_rwin();
	populate_amb();
	populate_cam();
	populate_light();
	populate_shapes();
}

/*
	1) Go over parsed lines and check identifiers
		a) RAC are unique
		b) if multiple Ls detected, make ->light into a linked list
		c) perhaps have a boolean value for L in the main map struct
	2) Ensure that there are no alpha characters in any string after identifiers
	3) once all checks complete create following functions
		a) extract_resolution()
		b) extract_ambient()
		c) extract_camera()
		d) if signle L: extract_light()
			else: extract_lights_list()
		e) create_objects()
	4) create ft_strtof() function
	5) populate t_tups and other data accordingly in 3 abcde
\ */
