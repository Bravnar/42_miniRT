#include "main.h"

/* NEW */
void	set_type(t_type *type, char *identifier)
{
	check_identifier(identifier);
	if (!ft_strcmp(identifier, "R"))
		*type = WINDOW;
	else if (!ft_strcmp(identifier, "A"))
		*type = AMBIENT;
	else if (!ft_strcmp(identifier, "C"))
		*type = CAMERA;
	else if (!ft_strcmp(identifier, "L"))
		*type = LIGHTS;
	else if (ft_strstr(GOOD_ID, identifier))
		*type = OBJECTS;
}

/* NEW */
char **set_type_and_clean(char **tmp, t_type *type)
{
	char	**ret;
	int		len;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len = ft_arr_len(tmp);
	set_type(type, tmp[0]);
	ret = malloc(sizeof(char *) * len);
	if (!ret)
		return (NULL);
	while (tmp[i])
	{
		ret[j] = ft_strdup(tmp[i++]);
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

/* NEW */
void	check_arr_extr(char **arr)
{
	int	i;
	int	len;

	i = 0;
	while(arr[i])
	{
		len = ft_strlen(arr[i]) - 1;
		if ((!ft_isalnum(arr[i][0]) && arr[i][0] != '-')\
			|| !ft_isalnum(arr[i][len]))
				err_template(M_INVALID_SEP, arr[i]);
		i++;
	}
}

/* NEW */
t_parse	*new_parse_node(char *line)
{
	t_parse	*node;
	char	**tmp;

	node = ft_calloc(1, sizeof(t_parse));
	if (!node)
		return (NULL);
	node->line = ft_strdup(line);
	if (line)
	{
		tmp = ft_megasplit(node->line, WHITESPACE);
		node->line_split = set_type_and_clean(tmp, &node->type);
		node->id = ft_strdup(tmp[0]);
		node->count = ft_arr_len(node->line_split);
		check_arr_extr(node->line_split);
		ft_free_arr(tmp);
	}
	node->next = NULL;
	return (node);
}

/* NEW */
void	add_node(t_parse **parsed, t_parse *new_node)
{
	t_parse	*tmp;

	if (!*parsed)
		*parsed = new_node;
	else
	{
		tmp = *parsed;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

/* NEW */
void	free_nodes(t_parse *list)
{
	t_parse	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->line);
		ft_free_arr(tmp->line_split);
		free(tmp->id);
		free(tmp);
	}
	tmp = NULL;
}

/* NEW */
void	print_nodes(t_parse **head)
{
	t_parse	*tmp;
	int		i;

	tmp = *head;
	while (tmp && tmp->line_split)
	{
		i = -1;
		printf("Type: [%s]\t", tmp->id);
		printf("Count: %d\t", tmp->count);
		printf("is_bonus [%d]\t", tmp->is_bonus);
		while (tmp->line_split[++i])
			printf("[%s] ", tmp->line_split[i]);
		printf("\n");
		tmp = tmp->next;
	}
}

/* OLD */
void	print_scene_details(void)
{
	t_rwin	res;
	t_amb	amb;
	t_cam	cam;

	res = get_map()->win;
	amb = get_map()->amb;
	cam = get_map()->cam;
	printf("Resolution: ---------------------------------------------:\n");
	printf("\tResolution x: %d\n\tResolution y: %d\n", res.x, res.y);
	printf("Ambient lighting: --------------:\n");
	printf("\tAmbient ratio: %f\n\tAmbient rgb: [%f,%f,%f]\n",
		amb.ratio, amb.rgb.r, amb.rgb.g, amb.rgb.b);
	printf("Camera: -------------------------------------------------:\n");
	printf("\tCamera position: [%f, %f, %f]\n",
		cam.point.x, cam.point.y, cam.point.z);
	printf("\tCamera vector: [%f, %f, %f]\n",
		cam.vector.x, cam.vector.y, cam.vector.z);
	printf("\tCamera FOV: %d\n", cam.fov);
	/* printf("Lights --------------------------------------------------:\n");
	print_light_nodes(get_scene_light());
	printf("Shapes ---------------------------------------------------:\n");
	print_object_nodes(get_scene_objs()); */
}
