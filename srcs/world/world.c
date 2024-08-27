#include "main.h"

t_color	color_at(t_world w, t_ray r)
{
	t_inter			inters;
	t_intersection	h;
	t_comps			comps;

	inters = intersect_world(w, r);
	h = hit(inters);
	if (h.t == -1)
		return (black());
	comps = prepare_comp(h, r);
	empty_inter(&inters);
	return (shade_hit(w, comps));
}

t_color	shade_hit(t_world w, t_comps comps)
{
	t_tup	views[2];
	bool	shadowed;

	t_color	tmp_color;

	views[0] = comps.eyev;
	views[1] = comps.normalv;
	shadowed = is_shadowed(w, comps.over_point);
	(void) w;
	tmp_color = lighting(comps.obj, comps.point, views, shadowed);
	print_color(tmp_color);
	return (tmp_color);
	// return (lighting(comps.obj, comps.point, views, shadowed));
}

t_inter	app_intersect(t_inter *xs, t_inter *new)
{
	t_inter	ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret.count = xs->count + new->count;
	if (!ret.count)
		ret.i = NULL;
	if (!ret.count)
		return (ret);
	ret.i = malloc(ret.count * sizeof(t_intersection));
	if (!ret.i)
	{
		ret.count = 0;
		return (ret);
	}
	while (j < xs->count)
		ret.i[i++] = xs->i[j++];
	j = 0;
	while (j < new->count)
		ret.i[i++] = new->i[j++];
	empty_inter(xs);
	empty_inter(new);
	return (ret);
}

t_inter	intersect_world(t_world w, t_ray r)
{
	t_obj	*tmp;
	t_inter	xs;
	t_inter	obj_tmp;

	xs.count = 0;
	tmp = w.shapes;
	obj_tmp.count = 0;
	obj_tmp.i = NULL;
	while (tmp)
	{
		obj_tmp = tmp->local_intersect(r, tmp);
		xs = app_intersect(&xs, &obj_tmp);
		tmp = tmp->next;
	}
	return (sort_inter(xs));
}

t_comps	prepare_comp(t_intersection h, t_ray r)
{
	t_comps	new;

	ft_bzero(&new, sizeof(t_comps));
	new.t = h.t;
	new.obj = h.shape;
	new.point = position(r, new.t);
	new.eyev = tuple_neg(r.direction);
	new.normalv = new.obj->local_normal_at(new.obj, new.point);
	if (dot(new.normalv, new.eyev) < 0)
	{
		new.is_inside = true;
		new.normalv = tuple_neg(new.normalv);
	}
	else
		new.is_inside = false;
	new.over_point = tuple_add(
			new.point,
			vector_scalar_mult(new.normalv, FLT_EPSILON));
	return (new);
}
