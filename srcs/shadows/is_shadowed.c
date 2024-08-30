#include "main.h"

bool	is_shadowed(t_world w, t_comps comps)
{
	t_tup			v;
	t_tup			direction;
	t_inter			*inter;
	t_intersection	h;
	t_ray			shadow_ray;

	v = tuple_sub(w.light->point, comps.over_point);
	direction = vector_norm(v);
	inter = intersect_world(w, ray_new(comps.over_point, direction));
	h = hit(&inter);
	if (h.shape)
	{
		shadow_ray = ray_new(
				tuple_add(comps.over_point, vector_scalar_mult(
						h.shape->local_normal_at(h.shape, comps.over_point),
						0.001)), direction);
		free_inter_nodes(inter);
		inter = intersect_world(w, shadow_ray);
		h = hit(&inter);
	}
	free_inter_nodes(inter);
	if (h.t != -1 && h.t < vector_mag(v))
		return (true);
	else
		return (false);
}
