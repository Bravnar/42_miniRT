#include "main.h"

void	add_obj_node(t_obj **head, t_obj *new_node)
{
	t_obj	*tmp;

	if (!*head)
		*head = new_node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

t_color	get_color(char *str)
{
	char	**rgb_split;
	t_color	rgb;

	rgb_split = ft_split(str, ',');
	rgb = color(ft_atoi(rgb_split[0]),
			ft_atoi(rgb_split[1]),
			ft_atoi(rgb_split[2]));
	ft_free_arr(rgb_split);
	return (rgb);
}

t_tup	get_point(char *str)
{
	char	**point_split;
	t_tup	n_point;

	point_split = ft_split(str, ',');
	n_point = point(ft_strtod(point_split[0]),
			ft_strtod(point_split[1]),
			ft_strtod(point_split[2]));
	ft_free_arr(point_split);
	return (n_point);
}

t_tup	get_vector(char *str)
{
	char	**vector_split;
	t_tup	n_vector;

	vector_split = ft_split(str, ',');
	n_vector = point(ft_strtod(vector_split[0]),
			ft_strtod(vector_split[1]),
			ft_strtod(vector_split[2]));
	ft_free_arr(vector_split);
	return (n_vector);
}

void	populate_shapes(void)
{
	t_parse	*tmp;
	t_obj	*node;

	tmp = get_scene()->file.parse;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line_split[0], "sp"))
		{
			node = (t_obj *)sphere_create(tmp->line_split);
			// node->transform(node, translation_matrix(node->point.x,
			// 										node->point.y,
			// 										node->point.z));
			add_obj_node(&get_scene()->obj_list, node);
		}
		else if (!ft_strcmp(tmp->line_split[0], "cy"))
		{
			node = (t_obj *)cyl_create(tmp->line_split);
			add_obj_node(&get_scene()->obj_list, node);
		}
		else if (!ft_strcmp(tmp->line_split[0], "pl"))
		{
			node = (t_obj *)plane_create(tmp->line_split);
			add_obj_node(&get_scene()->obj_list, node);
		}
		else if (!ft_strcmp(tmp->line_split[0], "cu"))
		{
			node = (t_obj *)cube_create(tmp->line_split);
			add_obj_node(&get_scene()->obj_list, node);
		}
		tmp = tmp->next;
	}
}
