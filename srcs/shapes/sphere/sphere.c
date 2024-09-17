#include "main.h"

/* ********************************* */
/* SPHERE STRUCT CREATION            */
/* To be called during map reading   */
/* ********************************* */

char	*get_name_s(t_obj *sphere)
{
	(void) sphere;
	return ("Sphere");
}

double	volume_s(t_obj *sphere)
{
	t_sphere	*sphere_1;
	double		radius;

	sphere_1 = (t_sphere *)sphere;
	radius = sphere_1->diameter / 2.0;
	return ((4.0 / 3.0) * PI * pow(radius, 3));
}

void	transform_s(t_obj *sphere, t_matrix transformation)
{
	sphere->transformation = matrix_mult(sphere->transformation,
			transformation);
	sphere->inverse_transformation = matrix_mult(sphere->inverse_transformation,
			inverse(transformation, 4));
}

void	pat_mat_sp(char **sphere_split, t_sphere *sphere)
{
	t_pattern	pat;
	t_color		prim;
	t_color		sec;

	prim = color_split(sphere_split[2]);
	if (!RT_BONUS)
	{
		pat = pat_default(prim);
		sphere->shape.material = material(pat, 0.9, 0.9, 200);
		sphere->shape.material.refractive_index = 0;
		sphere->shape.material.reflective = 0;
		sphere->shape.material.transparency = 0;
	}
	else
	{
		sec = color_split(sphere_split[4]);
		pat = pattern(prim, sec, range_int(sphere_split[3], 0, 3),
			matrix_mult(rotation_z(0), scaling_matrix(1, 1, 1)));
		sphere->shape.material = material (pat, 0.9, 0.9, 200);
		sphere->shape.material.refractive_index = range_double(sphere_split[6], 0.0, 5.0);
		sphere->shape.material.reflective = range_double(sphere_split[5], 0.0, 1.0);
		sphere->shape.material.transparency = range_double(sphere_split[7], 0.0, 1.0);
		sphere->shape.material.pattern.scale = range_double(sphere_split[8], 0, 20);
	}
}

t_sphere	*sphere_create(char **sphere_split, int i)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere_set_up(sphere, i);
	sphere->diameter = ft_strtod(sphere_split[1]);
	sphere->shape.point = str_to_point(sphere_split[0]);
	sphere->shape.dir_vector = vector(0, 0, 0);
	pat_mat_sp(sphere_split, sphere);
	sphere->shape.transform((t_obj *) sphere,
		matrix_mult(translation_matrix(sphere->shape.point.x,
				sphere->shape.point.y, sphere->shape.point.z),
			scaling_matrix(sphere->diameter / 2,
				sphere->diameter / 2, sphere->diameter / 2)));
	return (sphere);
}

void	sphere_destroy(t_obj *shape)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)shape;
	free(sphere);
}
