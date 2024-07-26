# include "main.h"

void	read_file(char *file_name, t_map *data)
{
	t_parse	*node;
	char	*line;

	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd == -1)
		exit(1);
	line = get_next_line(data->file.fd);
	while (line)
	{
		node = new_parse_node(line);
		add_node(&data->file.parse, node);
		free(line);
		line = get_next_line(data->file.fd);
	}
	print_nodes(&data->file.parse);
	free(line);
}

void	check_identifier(t_parse **head)
{
	t_parse	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->line_split && tmp->line_split[0])
		{
			if (!ft_strisalpha(tmp->line_split[0]))
				exit(1); //error_quit invalid scene
		}	
		tmp = tmp->next;
	}
}

void	get_amb_rgb(char *str)
{
	char **color_split;

	color_split = ft_split(str, ',');
	get_scene()->amb.rgb = color(ft_atoi(color_split[0]),
								ft_atoi(color_split[1]),
								ft_atoi(color_split[2]));
	ft_free_arr(color_split);
}


void	get_cam_point(char *str)
{
	char	**tup_split;
	char	*endptr;

	endptr = NULL;
	tup_split = ft_split(str, ',');
	get_scene()->cam.point = point(strtod(tup_split[0], &endptr),
							strtod(tup_split[1], &endptr),
							strtod(tup_split[2], &endptr));
	ft_free_arr(tup_split);
}

void	get_cam_vector(char *str)
{
	char	**tup_split;
	char	*endptr;

	endptr = NULL;
	tup_split = ft_split(str, ',');
	get_scene()->cam.vector = vector(strtod(tup_split[0], &endptr),
							strtod(tup_split[1], &endptr),
							strtod(tup_split[2], &endptr));
	ft_free_arr(tup_split);
}

void	populate_amb(void)
{
	t_parse *tmp;
	char	*endptr;

	endptr = NULL;
	tmp = get_scene()->file.parse;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line_split[0], "A"))
		{
			get_scene()->amb.ratio = strtod(tmp->line_split[1], &endptr); //replace by own strtod
			get_amb_rgb(tmp->line_split[2]);
			break ;
		}
		tmp = tmp->next;
	}
}

void	populate_cam(void)
{
	t_parse *tmp;

	tmp = get_scene()->file.parse;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line_split[0], "C"))
		{
			get_cam_point(tmp->line_split[1]);
			get_cam_vector(tmp->line_split[2]);
			get_scene()->cam.fov = ft_atoi(tmp->line_split[3]);
			break ;
		}
	tmp = tmp->next;
	}
}

void	populate_rwin(void)
{
	t_parse	*tmp;

	tmp = get_scene()->file.parse;
	// if (ft_lstsize((t_list *)tmp) != 3)
	// 	exit (1); //wrong list size;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line_split[0], "R"))
		{
			get_scene()->win.x = ft_atoi(tmp->line_split[1]);
			get_scene()->win.y = ft_atoi(tmp->line_split[2]);
			break ;
		}
		tmp = tmp->next;
	}
}

void	populate_scene_struct(char *file_name, t_map *scene)
{
	read_file(file_name, scene);
	check_identifier(&get_scene()->file.parse);
	populate_rwin();
	populate_amb();
	populate_cam();
}

void	print_scene_details(void)
{
	t_rwin	res = get_scene()->win;
	t_amb	amb = get_scene()->amb;
	t_cam	cam = get_scene()->cam;

	printf("Resolution x: %d\nResolution y: %d\n", res.x, res.y);
	printf("Ambient ratio: %f\nAmbient rgb: [%d,%d,%d]\n", amb.ratio, amb.rgb.r, amb.rgb.g, amb.rgb.b);
	printf("Camera position: [%f, %f, %f]\n", cam.point.x, cam.point.y, cam.point.z);
	printf("Camera vector: [%f, %f, %f]\n", cam.vector.x, cam.vector.y, cam.vector.z);
	printf("Camera FOV: %d\n", cam.fov);
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