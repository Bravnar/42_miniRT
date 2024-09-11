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
	if (sphere->material.pattern.noise)
		normal = perturb_normal(sphere, point, normal, sphere->material.pattern);
	return (normal);
}

t_sphere	*sphere(int i)
{
	t_sphere	*s;

	s = malloc(sizeof(t_sphere));
	if (!s)
		return (NULL);
	s->diameter = 2;
	s->shape.get_name = get_name_s;
	s->shape.volume = volume_s;
	s->shape.destroy = sphere_destroy;
	s->shape.transform = transform_s;
	s->shape.local_intersect = local_intersect_s;
	s->shape.local_normal_at = local_normal_at_s;
	s->shape.point = point(0, 0, 0);
	s->shape.dir_vector = vector(0, 0, 0);
	s->shape.material = mat_default();
	s->shape.next = NULL;
	s->shape.id = i;
	s->shape.transformation = identity();
	s->shape.inverse_transformation = identity();
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
	s->diameter = 2;
	s->shape.get_name = get_name_s;
	s->shape.volume = volume_s;
	s->shape.destroy = sphere_destroy;
	s->shape.transform = transform_s;
	s->shape.local_intersect = local_intersect_s;
	s->shape.local_normal_at = local_normal_at_s;
	s->shape.point = point(0, 0, 0);
	s->shape.dir_vector = vector(0, 0, 0);
	s->shape.material = mat_default();
	s->shape.material.refractive_index = 1.5;
	s->shape.material.transparency = 1;
	s->shape.next = NULL;
	s->shape.id = i;
	s->shape.transformation = identity();
	s->shape.inverse_transformation = identity();
	s->shape.transform((t_obj *) s,
		scaling_matrix(s->diameter / 2, s->diameter / 2, s->diameter / 2));
	return (s);
}
