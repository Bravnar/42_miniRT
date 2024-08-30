#include "main.h"

void	set_n1(t_comps *comps, t_inter *tmp_xs,
	t_intersection h, t_inter *containers)
{
	if (equal_intersect(tmp_xs->i, h))
	{
		if (!containers)
			comps->n1 = 1.0;
		else
			comps->n1 = last_inter_node(&containers)->\
				i.shape->material.refractive_index;
	}
	if (in_inter(&containers, tmp_xs->i.shape))
		remove_inter(&containers, tmp_xs);
	else
		append_inter_node(&containers, tmp_xs);
}

void	set_n1_n2(t_comps *comps, t_intersection h, t_inter **xs)
{
	t_inter	*containers;
	t_inter	*tmp_xs;

	containers = intersections(0);
	tmp_xs = *xs;
	while (tmp_xs)
	{
		set_n1(comps, tmp_xs, h, containers);
		if (equal_intersect(tmp_xs->i, h))
		{
			if (!containers)
				comps->n2 = 1.0;
			else
				comps->n2 = last_inter_node(&containers)->i.\
					shape->material.refractive_index;
		}
		tmp_xs = tmp_xs->next;
	}
}

t_ray	refract_ray(t_comps comps, double n_ratio,
	double cos_i, double sin2_t)
{
	double	cos_t;
	t_tup	direction;

	cos_t = sqrt(1 - sin2_t);
	direction = tuple_sub(vector_scalar_mult(comps.normalv,
				(n_ratio * cos_i - cos_t)),
			vector_scalar_mult(comps.eyev, n_ratio));
	return (ray_new(comps.under_point, direction));
}

t_color	refracted_color(t_world world, t_comps comps, int remaining)
{
	double	n_ratio;
	double	cos_i;
	double	sin2_t;
	t_ray	refracted_ray;

	if (comps.obj->material.transparency == 0)
		return (black());
	n_ratio = comps.n1 / comps.n2;
	cos_i = dot(comps.eyev, comps.normalv);
	sin2_t = (n_ratio * n_ratio) * (1 - cos_i * cos_i);
	if (sin2_t > 1)
		return (black());
	refracted_ray = refract_ray(comps, n_ratio, cos_i, sin2_t);
	return (color_scalarmult(comps.obj->material.transparency,
			color_at(world, refracted_ray, remaining - 1)));
}

double	schlick(t_comps comps)
{
	double	cos;
	double	sin2_t;
	double	r0;

	cos = dot(comps.eyev, comps.normalv);
	if (comps.n1 > comps.n2)
	{
		sin2_t = pow(comps.n1 / comps.n2, 2) * 1 - pow(cos, 2);
		if (sin2_t > 1)
			return (1);
		cos = sqrt(1 - sin2_t);
	}
	r0 = (comps.n1 - comps.n2) / pow(comps.n1 + comps.n2, 2);
	return (r0 + (1 - r0) * pow(1 - cos, 5));
}
