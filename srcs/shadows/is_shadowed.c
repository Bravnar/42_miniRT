#include "main.h"

t_ray	shadow_ray(t_comps comps, t_tup direction)
{
	t_tup	offset_point;

	offset_point = tuple_add(comps.over_point,
			vector_scalar_mult(direction, EPSILON));
	return (ray_new(offset_point, direction));
}

bool	is_shadowed(t_world w, t_comps comps)
{
	t_tup			v;
	t_tup			direction;
	t_ray			shadow_r;
	t_inter			*inter;
	t_intersection	h;


	v = tuple_sub(w.light->point, comps.over_point);
	direction = vector_norm(v);
	shadow_r = shadow_ray(comps, direction);
	inter = intersect_world(w, shadow_r);
	h = hit(&inter);
	free_inter_nodes(inter);
	return (h.t != -1 && h.t < vector_mag(v));
}
	/* t_ray			shadow_ray;
	 if (h.shape)
	{
		shadow_ray = ray_new(
				tuple_add(comps.over_point, vector_scalar_mult(
						h.shape->local_normal_at(h.shape, comps.over_point),
						0.0001)), direction);
		free_inter_nodes(inter);
		inter = intersect_world(w, shadow_ray);
		h = hit(&inter);
	} */
