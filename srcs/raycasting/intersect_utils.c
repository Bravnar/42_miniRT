#include "main.h"

void	free_inter_nodes(t_inter *inters)
{
	t_inter	*tmp;

	if (!inters)
		return ;
	while (inters)
	{
		tmp = inters;
		inters = inters->next;
		free(tmp);
	}
	tmp = NULL;
}

void	append_inter_node(t_inter **head, t_inter *node)
{
	t_inter	*tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

t_inter	*last_inter_node(t_inter **head)
{
	t_inter	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

bool	in_inter(t_inter **xs, t_obj *shape)
{
	t_inter	*tmp;

	tmp = *xs;
	while (tmp)
	{
		if (tmp->i.shape->id == shape->id)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	equal_intersect(t_intersection a, t_intersection b)
{
	return (a.t == b.t && a.shape->id == b.shape->id);
}
