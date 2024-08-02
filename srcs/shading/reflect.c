#include "main.h"

t_tup	vector_reflect(t_tup in, t_tup normal)
{
	return (tuple_sub(in, vector_scalar_mult(normal, dot(in, normal) * 2)));
}
