#include "main.h"

t_intersection	hit(t_inter inters)
{
	int				i;
	t_intersection	h;

	i = 0;
	h.t = -1;
	while (++i < inters.count)
	{
		if (inters.i[i].t >= 0)
		{
			if (h.t == -1)
				h = inters.i[i];
			else if (h.t > inters.i[i].t)
				h = inters.i[i];
		}
	}
	return (h);
}
