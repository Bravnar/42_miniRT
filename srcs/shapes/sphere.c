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

static void	transform(t_obj *shape, t_matrix transformation)
{
	shape->transformation = matrix_mult(shape->transformation,
			transformation);
	shape->inverse_transformation = matrix_mult(shape->inverse_transformation,
			inverse(transformation, 4));
}

t_sphere	*sphere_create(char **sphere_split)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->diameter = ft_strtod(sphere_split[2]);
	sphere->shape.get_name = get_name;
	sphere->shape.volume = volume;
	sphere->shape.destroy = sphere_destroy;
	sphere->shape.transform = transform;
	sphere->shape.point = get_point(sphere_split[1]);
	sphere->shape.dir_vector = vector(0, 0, 0);//parse_vector;
	sphere->shape.material = material(get_color(sphere_split[3]), 0.9, 0.9, 200);
	sphere->shape.color = ;//parse_rgb; // by default to red
	sphere->shape.next = NULL;
	sphere->shape.transformation = identity();
	sphere->shape.inverse_transformation = identity();
	return (sphere);
}

void	sphere_destroy(t_obj *shape)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)shape;
	free(sphere);
}
