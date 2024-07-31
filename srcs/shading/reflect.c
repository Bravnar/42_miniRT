#include "main.h"

t_tup	vector_reflect(t_tup in, t_tup normal)
{
	return (vector_scalar_mult(
			tuple_sub(in, normal), dot(in, normal) * 2));
}
