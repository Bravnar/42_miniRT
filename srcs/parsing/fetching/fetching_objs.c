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

t_obj	*fetch_objs(t_parse **head)
{
	t_obj	*obj_list;
	t_obj	*(*create_shape)(char **, int);
	t_parse *tmp;
	int		i;

	i = 0;
	obj_list = NULL;
	tmp = *head;
	while(tmp)
	{
		create_shape = NULL;
		if (!ft_strcmp(tmp->id, "sp"))
			create_shape = (t_obj *(*)(char **, int)) sphere_create;
		else if (!ft_strcmp(tmp->id, "cy"))
			create_shape = (t_obj *(*)(char **, int)) cyl_create;
		else if (!ft_strcmp(tmp->id, "pl"))
			create_shape = (t_obj *(*)(char **, int)) plane_create;
		else if (!ft_strcmp(tmp->id, "cu"))
			create_shape = (t_obj *(*)(char **, int)) cube_create;
		if (create_shape)
			add_obj_node(&obj_list, create_shape(tmp->line_split, i++));
		tmp = tmp->next;
	}
	return (obj_list);
}