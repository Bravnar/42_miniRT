#include "main.h"

t_inter	*local_intersect_pl(t_ray r, t_obj *plane)
{
	t_tup	to_orig;
	double	dot_prod;
	double	t;
	t_inter	*inter;

	dot_prod = dot(plane->local_normal_at(plane,
				plane->saved_ray.point), plane->saved_ray.direction);
	inter = NULL;
	if (!equal(dot_prod, 0))
	{
		to_orig = tuple_sub(plane->point, plane->saved_ray.point);
		t = dot(to_orig, plane->local_normal_at(plane, r.point)) / dot_prod;
		if (t >= 0)
			inter = new_inter_node(intersection(t, plane));
	}
	if (!inter)
		return (NULL);
	return (inter);
}

t_tup	local_normal_at_pl(t_obj *plane, t_tup point)
{
	t_tup	normal;
	normal = vector_norm(
			matrix_mult_tup(plane->transformation, plane->dir_vector));
	if (plane->material.pattern.scale)
		normal = perturb_normal(plane, point, normal,
				plane->material.pattern);
	return (normal);
}

t_plane	*plane(int i)
{
	t_plane	*p;

	p = malloc(sizeof(t_plane));
	if (!p)
		return (NULL);
	p->shape.get_name = get_name_pl;
	p->shape.volume = 0;
	p->shape.destroy = plane_destroy;
	p->shape.local_normal_at = local_normal_at_pl;
	p->shape.transform = transform_pl;
	p->shape.local_intersect = local_intersect_pl;
	p->shape.point = point(0, 0, 0);
	p->shape.dir_vector = vector(0, 1, 0);
	p->shape.material = mat_default();
	p->shape.transformation = identity();
	p->shape.id = i;
	p->shape.inverse_transformation = identity();
	p->shape.next = NULL;
	return (p);
}
