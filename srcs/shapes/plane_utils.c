#include "main.h"

t_inter	local_intersect_pl(t_ray r, t_obj *plane)
{
	double	t;
	t_inter	inter;

	inter.count = 0;
	if (equal(r.direction.y, 0))
		return (inter);
	inter.i = malloc(sizeof(t_intersection) * 1);
	if (!inter.i)
		return (inter);
	t = -r.point.y / r.direction.y;
	inter.count++;
	inter.i[0] = intersection(t, plane);
	return (inter);
}

t_tup	local_normal_at_pl(t_obj *plane, t_tup point)
{
	(void) point;
	return (vector_norm(
			matrix_mult_tup(plane->transformation, vector(0, 1, 0))));
}

t_plane	*plane(void)
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
	p->shape.inverse_transformation = identity();
	p->shape.next = NULL;
	return (p);
}
