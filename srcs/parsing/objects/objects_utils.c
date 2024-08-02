#include "main.h"

void	print_object_nodes(t_obj **head)
{
	t_obj	*tmp;
	int		i;

	i = 1;
	tmp = *head;
	while(tmp)
	{
		printf("\tShape %d:\n", i++);
		printf("\t\tType: %s\n", tmp->get_name(tmp));
		printf("\t\tDiameter: %f\n", ((t_sphere *)tmp)->diameter);
		printf("\t\tPoint: %f, %f, %f\n", tmp->point.x, tmp->point.y, tmp->point.z);
		printf("\t\tVector: %f, %f, %f\n", tmp->dir_vector.x,
											tmp->dir_vector.y,
											tmp->dir_vector.z);
		printf("\t\tColor: %d, %d, %d\n",
		 					tmp->material.color.r,
							tmp->material.color.g,
							tmp->material.color.b);
		tmp = tmp->next;
	}
}
