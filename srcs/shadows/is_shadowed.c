#include "main.h"

bool	is_shadowed(t_world w, t_tup point)
{
	t_tup			v;
	t_tup			direction;
	t_inter			inter;
	t_intersection	h;
	t_ray			shadow_ray;

	v = tuple_sub(w.light->point, point);
	direction = vector_norm(v);
	inter = intersect_world(w, ray_new(point, direction));
	h = hit(inter);
	if (h.shape)
	{
		shadow_ray = ray_new(
				tuple_add(point, vector_scalar_mult(
						h.shape->local_normal_at(h.shape, point),
						0.001)), direction);
		empty_inter(&inter);
		inter = intersect_world(w, shadow_ray);
		h = hit(inter);
	}
	empty_inter(&inter);
	if (h.t != -1 && h.t < vector_mag(v))
		return (true);
	else
		return (false);
}
