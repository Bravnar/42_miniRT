#include "main.h"

bool	check_cap(t_ray r, double t)
{
	double	x;
	double	z;
	double	result;

	x = r.point.x + r.direction.x * t;
	z = r.point.z + r.direction.z * t;
	result = pow(x, 2) + pow(z, 2);
	return (result < 1 || equal(result, 1));
}

void	intersect_caps(t_obj *obj, t_ray r, t_inter *inter)
{
	t_cyl	*cyl;
	double	t;

	cyl = (t_cyl *) obj;
	if (!cyl->closed || equal(obj->dir_vector.y, 0))
		return ;
	t = (cyl->min - r.point.y) / r.direction.y;
	if (check_cap(r, t))
		add_inter_node(&inter, new_inter_node(intersection(t, obj)));
	t = (cyl->max - r.point.y) / r.direction.y;
	if (check_cap(r, t))
		add_inter_node(&inter, new_inter_node(intersection(t, obj)));
}


