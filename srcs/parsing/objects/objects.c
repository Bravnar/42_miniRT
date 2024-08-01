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

void	populate_shapes(void)
{
	t_parse	*tmp;
	t_obj	*node;

	tmp = get_scene()->file.parse;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line_split[0], "sp"))
		{
			node = (t_obj *)sphere_create(ft_strtod(tmp->line_split[2]));
			add_obj_node(&get_scene()->obj_list, node);
		}
		tmp = tmp->next;
	}
}

