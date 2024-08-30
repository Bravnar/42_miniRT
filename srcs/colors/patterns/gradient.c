#include "main.h"

t_color	gradient_pattern(t_obj *shape, t_tup point, t_pattern pat)
{
	t_color	distance;
	double	fraction;
	t_tup	object_point;
	t_tup	pattern_point;

	object_point = matrix_mult_tup(shape->inverse_transformation, point);
	pattern_point = matrix_mult_tup(pat.inverse_transformation, object_point);
	distance = color_sub(pat.colors[1], pat.colors[0]);
	double range = 2.0;
	fraction = (pattern_point.x + range / 2.0) / range;

	// Prevent fraction from exceeding 1 or dropping below 0
	if (fraction < 0)
		fraction = 0;
	if (fraction > 1)
		fraction = 1;
	//fraction = pattern_point.x - floor(pattern_point.x);
	if (fraction == 0 && pattern_point.x == 0)
		return (pat.colors[0]);
	else if (fraction == 0 && pattern_point.x == 1)
		return (pat.colors[1]);
	return (color_add(pat.colors[0], color_scalarmult(fraction, distance)));
}
