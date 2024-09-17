#include "main.h"

void	print_light_nodes(t_light **head)
{
	t_light	*tmp;
	int		i;

	tmp = *head;
	i = 1;
	while (tmp)
	{
		printf("\tLight %d:\n", i++);
		printf("\t\tPoint: %f, %f, %f\n", tmp->point.x, tmp->point.y,
			tmp->point.z);
		printf("\t\tBrightness: %f\n", tmp->bright);
		printf("\t\tColor: %f, %f, %f\n", tmp->rgb.r, tmp->rgb.g, tmp->rgb.b);
		tmp = tmp->next;
	}
}

void	print_nodes(t_parse **head)
{
	t_parse	*tmp;
	int		i;

	tmp = *head;
	while (tmp && tmp->line_split)
	{
		i = -1;
		printf("Type: [%s]\t", tmp->id);
		printf("Count: %d\t", tmp->count);
		printf("is_bonus [%d]\t", tmp->is_bonus);
		while (tmp->line_split[++i])
			printf("[%s] ", tmp->line_split[i]);
		printf("\n");
		tmp = tmp->next;
	}
}

void	print_scene_details(void)
{
	t_rwin	res;
	t_amb	amb;
	t_cam	cam;
	t_light	*light;

	res = get_map()->win;
	amb = get_map()->amb;
	cam = get_map()->cam;
	light = get_map()->light;
	printf("Resolution: ---------------------------------------------:\n");
	printf("\tResolution x: %d\n\tResolution y: %d\n", res.x, res.y);
	printf("Ambient lighting: --------------:\n");
	printf("\tAmbient ratio: %f\n\tAmbient rgb: [%f,%f,%f]\n",
		amb.ratio, amb.rgb.r, amb.rgb.g, amb.rgb.b);
	printf("Camera: -------------------------------------------------:\n");
	printf("\tCamera position: [%f, %f, %f]\n",
		cam.point.x, cam.point.y, cam.point.z);
	printf("\tCamera vector: [%f, %f, %f]\n",
		cam.vector.x, cam.vector.y, cam.vector.z);
	printf("\tCamera FOV: %d\n", cam.fov);
	printf("Lights --------------------------------------------------:\n");
	print_light_nodes(&light);
	printf("Shapes ---------------------------------------------------:\n");
	print_object_nodes(get_scene_objs());
}

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
		printf("\t\tType: %s\n", name);
		if (!ft_strcmp(name, "Sphere"))
			printf("\t\tDiameter: %.2f\n", ((t_sphere *)tmp)->diameter);
		else if (!ft_strcmp(name, "Cylinder"))
			printf("\t\tDiameter: %.2f\n\t\tHeight: %f\n",
				((t_cyl *)tmp)->diameter, ((t_cyl *)tmp)->height);
		else if (!ft_strcmp(name, "Cube"))
			printf("\t\tLength: %.2f\n\t\tWidth: %.2f\n\t\tHeight: %.2f\n",
				((t_cube *)tmp)->length, ((t_cube *)tmp)->width, ((t_cube *)tmp)->height);
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
