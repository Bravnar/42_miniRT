#include "main.h"

bool	is_shadowed(t_world w, t_tup point)
{
	t_tup			v;
	t_tup			direction;
	t_inter			inter;
	t_intersection	h;
	double			distance;

	v = tuple_sub(w.light->point, point);
	distance = vector_mag(v);
	direction = vector_norm(v);
	inter = intersect_world(w, ray_new(point, direction));
	h = hit(inter);
	if (h.t != -1 && h.t < distance)
		return (true);
	else
		return (false);
}
