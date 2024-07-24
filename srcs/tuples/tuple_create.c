#include "main.h"

t_tup	tuple(double x, double y, double z, int w)
{
	t_tup	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = w;
	return (new);
}

t_tup	point(double x, double y, double z)
{
	return (tuple(x, y, z, 1));
}

t_tup	vector(double x, double y, double z)
{
	return (tuple(x, y, z, 0));
}
