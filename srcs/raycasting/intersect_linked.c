#include "main.h"

t_inter	*new_inter_node(t_intersection i)
{
	t_inter	*node;

	node = ft_calloc(1, sizeof(t_inter));
	if (!node)
		return (NULL);
	node->i = i;
	node->next = NULL;
	return (node);
}

void add_inter_nodes(t_inter **head, t_inter **new_nodes)
{
	t_inter *tmp;

	if (new_nodes == NULL)
		return ;
	tmp = *new_nodes;
	while (tmp)
	{
		add_inter_node(head, new_inter_node(tmp->i));
		tmp = tmp->next;
	}
}

void	add_inter_node(t_inter **head, t_inter *new_node)
{
	t_inter	*tmp;

	if (!*head)
		*head = new_node;
	else
	{
		tmp = *head;
		if (new_node->i.t <= tmp->i.t)
		{
			new_node->next = tmp;
			*head = new_node;
		}
		else
		{
			while (tmp->next && tmp->next->i.t < new_node->i.t)
				tmp = tmp->next;
			new_node->next = tmp->next;
			tmp->next = new_node;
		}
	}
}

void	remove_inter(t_inter **head, t_inter *to_remove)
{
	t_inter	*tmp;

	tmp = *head;
	if (tmp == to_remove)
	{
		*head = (*head)->next;
		free(tmp);
	}
	else
	{
		while (tmp->next && tmp->next != to_remove)
		{
			tmp = tmp->next;
		}
		if (tmp->next == to_remove)
		{
			tmp->next = to_remove->next;
			free(to_remove);
		}
	}
}
