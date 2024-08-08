#include "main.h"

t_material	material(t_color c, double d, double s, double sh)
{
	t_material	new_mat;

	new_mat.amb = get_scene()->amb.ratio;
	new_mat.diffuse = d;
	new_mat.specular = s;
	new_mat.color = c;
	new_mat.shininess = sh;
	return (new_mat);
}

t_material	mat_default(void)
{
	t_material	new_mat;

	new_mat.amb = 0.1;
	new_mat.diffuse = 0.9;
	new_mat.specular = 0.9;
	new_mat.color = color(255, 255, 255);
	new_mat.shininess = 200;
	return (new_mat);
}
