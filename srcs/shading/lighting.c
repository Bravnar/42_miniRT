#include "main.h"

t_color	compute_eff_color(t_obj *shape, t_tup p)
{
	t_color	eff_color;
	t_color	intensity;

	intensity = get_scene()->light->intensity;
	eff_color = color_blend(
			shape->material.pattern.color_at(shape->dir_vector,
				p, shape->material.pattern), intensity);
	return (eff_color);
}

t_tup	light_vector(t_tup point)
{
	return (vector_norm(tuple_sub(get_scene()->light->point, point)));
}

t_color	lighting(t_obj *shape, t_tup p, t_tup views[2], bool in_shadow)
{
	t_color	eff_color;
	t_color	diff;
	t_color	spec;
	t_tup	v[3];
	double	light_dot_normal;

	eff_color = compute_eff_color(shape, p);
	v[0] = light_vector(p);
	v[1] = views[0];
	v[2] = views[1];
	light_dot_normal = dot(v[0], views[1]);
	diff = diffuse(light_dot_normal, shape->material, eff_color);
	spec = specular(light_dot_normal, shape->material, v);
	if (in_shadow)
		return (ambient(eff_color, shape->material));
	return (color_add(ambient(eff_color, shape->material),
			color_add(diff, spec)));
}
