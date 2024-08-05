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
