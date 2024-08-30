#include "main.h"

t_color	reflected_color(t_world world, t_comps comps, int remaining)
{
	t_ray	reflect_ray;
	t_color	color;

	if (comps.obj->material.reflective == 0 || remaining == 0)
		return (black());
	reflect_ray = ray_new(comps.over_point, comps.reflectv);
	color = color_at(world, reflect_ray, remaining - 1);
	return (color_scalarmult(comps.obj->material.reflective, color));
}
