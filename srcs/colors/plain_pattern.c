#include "main.h"

t_color	plain_pattern(t_tup dir, t_tup point, t_pattern pat)
{
	(void) dir;
	(void) point;
	return (pat.colors[0]);
}
