#include "main.h"

t_color	plain_pattern(t_obj *shape, t_tup point, t_pattern pat)
{
	(void) point;
	(void) shape;
	return (pat.colors[0]);
}
