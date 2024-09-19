#include "main.h"

void	add_light_node_front(t_light *light, t_light **head)
{
	light->next = *head;
	*head = light;
}

void	remove_first_light(t_light **head)
{
	t_light	*tmp;

	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
