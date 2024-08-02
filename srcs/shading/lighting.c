#include "main.h"

t_color	compute_eff_color(t_material m)
{
	t_color	eff_color;
	t_color	intensity;

	intensity = get_scene()->light->intensity;
	eff_color = color_blend(m.color, intensity);
	return (eff_color);
}

t_tup	light_vector(t_tup point)
{
	return (vector_norm(tuple_sub(get_scene()->light->point, point)));
}

t_color	lighting(t_material m, t_tup p, t_tup ev, t_tup nv)
{
	t_color	eff_color;
	t_tup	light_v;
	t_color	diff;
	t_color	spec;
	double	light_dot_normal;

	eff_color = compute_eff_color(m);
	light_v = light_vector(p);
	light_dot_normal = dot(light_v, nv);
	diff = diffuse(light_dot_normal, m, eff_color);
	spec = specular(light_dot_normal, light_v, m, ev, nv);
	return (color_add(ambient(eff_color, m), color_add(diff, spec)));
}
