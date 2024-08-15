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
	return (shade_hit(w, comps));
}

t_color	shade_hit(t_world w, t_comps comps)
{
	(void) w;
	return (lighting(comps.obj->material,
					comps.point, 
					comps.eyev, 
					comps.normalv));
}

t_inter	app_intersect(t_inter *xs, t_inter *new)
{
	t_inter ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret.count = xs->count + new->count;
	ret.i = malloc(ret.count * sizeof(t_inter));
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
	if (xs->count)
		free(xs->i);
	if (new->count)
		free(new->i);
	return ret;
}

t_inter	intersect_world(t_world w, t_ray r)
{
	t_obj	*tmp;
	t_inter	xs;
	t_inter	sphere_tmp;

	xs.count = 0;
	tmp = w.shapes;
	sphere_tmp.count = 0;
	sphere_tmp.i = NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->get_name(tmp), "Sphere"))
		{
			sphere_tmp = tmp->local_intersect(r, tmp);
			xs = app_intersect(&xs, &sphere_tmp);
		}
		tmp = tmp->next;
	}
	return (sort_inter(xs));
}

t_world	create_world(void)
{
	t_world	w;

	w.light = get_scene()->light;
	w.shapes = get_scene()->obj_list;
	return w;
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
	return (new);
}
