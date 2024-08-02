#include "main.h"

t_light	*new_light_node(t_tup point, double bright, t_color rgb)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return (NULL);
	light->point = point;
	light->bright = bright;
	light->rgb = rgb;
	light->next = NULL;
	return (light);
}

void	add_light_node(t_light **head, t_light *new_node)
{
	t_light	*tmp;

	if( !*head)
		*head = new_node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void	free_light_nodes(t_light *light)
{
	t_light	*tmp;

	if (!light)
		return ;
	while (light)
	{
		tmp = light;
		light = light->next;
		free(tmp);
	}
	tmp = NULL;
}

void	print_light_nodes(t_light **head)
{
	t_light	*tmp;
	int		i;

	tmp = *head;
	i = 1;
	while(tmp)
	{
		printf("\tLight %d:\n", i++);
		printf("\t\tPoint: %f, %f, %f\n", tmp->point.x, tmp->point.y, tmp->point.z);
		printf("\t\tBrightness: %f\n", tmp->bright);
		printf("\t\tColor: %d, %d, %d\n", tmp->rgb.r, tmp->rgb.g, tmp->rgb.b);
		tmp = tmp->next;
	}
}