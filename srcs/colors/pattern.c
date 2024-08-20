#include "main.h"

t_pattern	pattern(t_color a, t_color b, e_patt_type type)
{
	t_pattern	pat;

	pat.colors[0] = a;
	pat.colors[1] = b;
	if (type == PLAIN)
		pat.color_at = plain_pattern;
	return (pat);
}
