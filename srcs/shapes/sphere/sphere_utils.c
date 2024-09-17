#include "main.h"

t_inter	*local_intersect_s(t_ray r, t_obj *sphere)
{
	(void) r;
	return (intersect(sphere));
}

t_tup	local_normal_at_s(t_obj *sphere, t_tup point)
{
	t_tup	normal;

	normal = normal_at(sphere, point);
	if (sphere->material.pattern.scale > 1)
		normal = perturb_normal(sphere, point, normal,
				sphere->material.pattern);
	return (normal);
}

t_sphere	*sphere(int i)
{
	t_sphere	*s;

	s = malloc(sizeof(t_sphere));
	if (!s)
		return (NULL);
	sphere_set_up(s, i);
	s->diameter = 2;
	s->shape.point = point(0, 0, 0);
	s->shape.dir_vector = vector(0, 0, 0);
	s->shape.material = mat_default();
	s->shape.transform((t_obj *) s,
		scaling_matrix(s->diameter / 2, s->diameter / 2, s->diameter / 2));
	return (s);
}

t_sphere	*glass_sphere(int i)
{
	t_sphere	*s;

	s = malloc(sizeof(t_sphere));
	if (!s)
		return (NULL);
	sphere_set_up(s, i);
	s->diameter = 2;
	s->shape.point = point(0, 0, 0);
	s->shape.dir_vector = vector(0, 0, 0);
	s->shape.material = mat_default();
	s->shape.material.refractive_index = 1.5;
	s->shape.material.transparency = 1;
	s->shape.transform((t_obj *) s,
		scaling_matrix(s->diameter / 2, s->diameter / 2, s->diameter / 2));
	return (s);
}

void	sphere_set_up(t_sphere *sphere, int i)
{
	sphere->shape.id = i;
	sphere->shape.get_name = get_name_s;
	sphere->shape.volume = volume_s;
	sphere->shape.destroy = sphere_destroy;
	sphere->shape.transform = transform_s;
	sphere->shape.local_intersect = local_intersect_s;
	sphere->shape.local_normal_at = local_normal_at_s;
	sphere->shape.next = NULL;
	sphere->shape.transformation = identity();
	sphere->shape.inverse_transformation = identity();
}
