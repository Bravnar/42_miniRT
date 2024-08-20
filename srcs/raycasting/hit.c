#include "main.h"

t_intersection	copy_intersection(t_intersection i)
{
	t_intersection	new;

	new.t = i.t;
	new.shape = i.shape;
	return (new);
}

t_intersection	hit(t_inter inters)
{
	int				i;
	t_intersection	h;

	i = -1;
	h = intersection(-1, NULL);
	if (inters.count == 0)
		return (h);
	while (++i < inters.count)
	{
		if (inters.i[i].t > 0)
			return (copy_intersection(inters.i[i]));
	}
	return (h);
}

t_intersection	nhit(t_inter inters)
{
	int				i;
	t_intersection	h;

	i = 0;
	h = intersection(-1, NULL);
	while (i < inters.count)
	{
		if (inters.i[i].t >= 0)
		{
			h = copy_intersection(inters.i[i]);
			return (h);
		}
		i++;
	}
	return (h);
}
