#include "main.h"

t_color	ambient(t_color effective_color, t_material mat)
{
	return (color_scalarmult(mat.amb, effective_color));
}

t_color	diffuse(double ldn, t_material m, t_color eff_color)
{
	if (ldn < 0)
		return (black());
	else
		return (color_scalarmult(m.diffuse * ldn, eff_color));
}

t_color	specular(double ldn, t_tup light_v, t_material m, t_tup ev, t_tup nv)
{
	t_tup	reflect_v;
	t_color	intensity;
	double	reflect_dot_eye;

	intensity = get_scene()->light->intensity;
	if (ldn < 0)
		return (black());
	else
	{
		reflect_v = vector_reflect(tuple_neg(light_v), nv);
		reflect_dot_eye = dot(reflect_v, ev);
		if (reflect_dot_eye < 0 || equal(reflect_dot_eye, 0))
			return (black());
		else
			return (color_scalarmult(
					pow(reflect_dot_eye, m.shininess) * m.specular, intensity));
	}
}
