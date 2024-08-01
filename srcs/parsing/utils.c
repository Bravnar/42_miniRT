#include "main.h"

t_parse	*new_parse_node(char *line)
{
	t_parse	*node;

	node = ft_calloc(1, sizeof(t_parse));
	if (!node)
		return (NULL);
	node->line = ft_strdup(line);
	if (line)
		node->line_split = ft_megasplit(node->line, WHITESPACE);
	node->next = NULL;
	return (node);
}

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
		free(tmp);
	}
	tmp = NULL;
}

void	print_nodes(t_parse **head)
{
	t_parse	*tmp;
	int		i;

	tmp = *head;
	while (tmp)
	{
		i = -1;
		while (tmp->line_split[++i])
		{
			if (!ft_strcmp(tmp->line_split[i], " "))
				printf("Empty_line\n");
			printf("[%s] ", tmp->line_split[i]);
		}
		printf("\n");
		tmp = tmp->next;
	}
}

void	print_scene_details(void)
{
	t_rwin	res = get_scene()->win;
	t_amb	amb = get_scene()->amb;
	t_cam	cam = get_scene()->cam;
	
	printf("Resolution: ---------------------------------------------:\n");
	printf("\tResolution x: %d\n\tResolution y: %d\n", res.x, res.y);
	printf("Ambient lighting: --------------:\n");
	printf("\tAmbient ratio: %f\n\tAmbient rgb: [%d,%d,%d]\n",
			amb.ratio, amb.rgb.r, amb.rgb.g, amb.rgb.b);
	printf("Camera: -------------------------------------------------:\n");
	printf("\tCamera position: [%f, %f, %f]\n",
			cam.point.x, cam.point.y, cam.point.z);
	printf("\tCamera vector: [%f, %f, %f]\n",
			cam.vector.x, cam.vector.y, cam.vector.z);
	printf("\tCamera FOV: %d\n", cam.fov);
	printf("Lights --------------------------------------------------:\n");
	print_light_nodes(&get_scene()->light);
	printf("Shapes ---------------------------------------------------:\n");
}
