#include "main.h"

t_color	stripe_pattern(t_obj *shape, t_tup point, t_pattern pat)
{
	t_tup	object_point;
	t_tup	pattern_point;

	object_point = matrix_mult_tup(shape->inverse_transformation, point);
	pattern_point = matrix_mult_tup(pat.inverse_transformation, object_point);
	if (equal(fmod(floor(pattern_point.x), 2), 0))
		return (pat.colors[0]);
	else
		return (pat.colors[1]);
}
