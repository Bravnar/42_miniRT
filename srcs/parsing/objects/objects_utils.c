#include "main.h"

void	print_object_nodes(t_obj **head)
{
	t_obj	*tmp;
	int		i;

	i = 1;
	tmp = *head;
	while(tmp)
	{
		char	*name = tmp->get_name(tmp);
		printf("\tShape %d:\n", i++);
		printf("\t\tType: %s\n", name);
		if (!ft_strcmp(name, "Sphere"))
			printf("\t\tDiameter: %.2f\n", ((t_sphere *)tmp)->diameter);
		else if (!ft_strcmp(name, "Cylinder"))
		{
			printf("\t\tDiameter: %.2f\n\t\tHeight: %f\n",
				((t_cyl *)tmp)->diameter, ((t_cyl *)tmp)->height);
		}
		else if (!ft_strcmp(name, "Cube"))
		{
			printf("\t\tLength: %.2f\n\t\tWidth: %.2f\n\t\tHeight: %.2f\n",
				((t_cube *)tmp)->length, ((t_cube *)tmp)->width, ((t_cube *)tmp)->height);
		}
		printf("\t\tPoint: %.2f, %.2f, %.2f\n",
			tmp->point.x, tmp->point.y, tmp->point.z);
		printf("\t\tVector: %.2f, %.2f, %.2f\n", tmp->dir_vector.x,
											tmp->dir_vector.y,
											tmp->dir_vector.z);
		printf("\t\tColor: %f, %f, %f\n",
		 					tmp->material.color.r,
							tmp->material.color.g,
							tmp->material.color.b);
		tmp = tmp->next;
	}
}
