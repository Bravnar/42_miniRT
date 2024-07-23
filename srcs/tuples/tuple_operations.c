#include "main.h"

t_tup	tuple_sub(t_tup a, t_tup b)
{
	return (tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w ^ b.w));
}

t_tup	tuple_neg(t_tup a)
{
	return (tuple(-a.x, -a.y, -a.z, -a.w));
}
