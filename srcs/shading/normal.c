#include "main.h"

t_tup	normal_at(t_obj *sphere, t_tup point)
{
	return (vector_norm(tuple_sub(point, sphere->point)));
}


