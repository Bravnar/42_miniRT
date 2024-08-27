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



t_sphere	*sphere_create(char **sphere_split)
{
	t_sphere	*sphere;
	t_pattern	pat;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->diameter = ft_strtod(sphere_split[2]);
	sphere->shape.get_name = get_name_s;
	sphere->shape.volume = volume_s;
	sphere->shape.destroy = sphere_destroy;
	sphere->shape.transform = transform_s;
	sphere->shape.local_intersect = local_intersect_s;
	sphere->shape.local_normal_at = local_normal_at_s;
	sphere->shape.point = get_point(sphere_split[1]);
	sphere->shape.dir_vector = vector(0, 0, 0);
	pat = pattern(get_color(sphere_split[3]), c("blue"), STRIPE,
			matrix_mult(rotation_z_pat(45, "sphere"),
				scaling_matrix(0.25, 0.25, 0.25)));
	sphere->shape.material = material(pat, 0.9, 0.9, 200);
	sphere->shape.next = NULL;
	sphere->shape.transformation = identity();
	sphere->shape.inverse_transformation = identity();
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
