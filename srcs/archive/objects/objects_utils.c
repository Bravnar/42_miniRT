#include "main.h"

void	print_object_nodes(t_obj **head)
{
	t_obj	*tmp;
	int		i;
	char	*name;

	i = 1;
	tmp = *head;
	while (tmp)
	{
		name = tmp->get_name(tmp);
		printf("\tShape %d:\n", i++);
		print_shape_specs(tmp, name);
		printf("\t\tPoint: %.2f, %.2f, %.2f\n",
			tmp->point.x, tmp->point.y, tmp->point.z);
		printf("\t\tVector: %.2f, %.2f, %.2f\n", tmp->dir_vector.x,
			tmp->dir_vector.y,
			tmp->dir_vector.z);
		printf("\t\tColor: %f, %f, %f\n", tmp->material.color.r,
			tmp->material.color.g,
			tmp->material.color.b);
		tmp = tmp->next;
	}
}
