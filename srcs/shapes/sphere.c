#include "main.h"

/* ********************************* */
/* SPHERE STRUCT CREATION            */
/* To be called during map reading   */
/* ********************************* */

static char	*get_name(t_obj *shape)
{
	(void) shape;
	return ("Sphere");
}

static double	volume(t_obj *shape)
{
	t_sphere	*sphere;
	double		radius;

	sphere = (t_sphere *)shape;
	radius = sphere->diameter / 2.0;
	return ((4.0 / 3.0) * PI * pow(radius, 3));
}

t_sphere	*sphere_create(double diameter)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->diameter = diameter;
	sphere->shape.get_name = get_name;
	sphere->shape.volume = volume;
	sphere->shape.destroy = sphere_destroy;
	sphere->shape.point = ---;//parse_point;
	sphere->shape.dir_vector = ---;//parse_vector;
	sphere->shape.rgb = ---;//parse_rgb;
	sphere->shape.next = NULL;
	return (sphere);
}

void	sphere_destroy(t_obj *shape)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)shape;
	free(sphere);
}
