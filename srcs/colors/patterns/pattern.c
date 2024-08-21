#include "main.h"

static void	transform(t_pattern *pat, t_matrix transformation)
{
	pat->transformation = matrix_mult(pat->transformation, transformation);
	pat->inverse_transformation = matrix_mult(pat->inverse_transformation,
			inverse(transformation, 4));
}


t_pattern	pattern(t_color a, t_color b, t_patt_type type, t_matrix trans)
{
	t_pattern	pat;

	pat.colors[0] = a;
	pat.colors[1] = b;
	pat.transformation = identity();
	pat.inverse_transformation = identity();
	pat.transform = transform;
	pat.transform(&pat, trans);
	if (type == PLAIN)
		pat.color_at = plain_pattern;
	else if (type == STRIPE)
		pat.color_at = stripe_pattern;
	else if (type == GRADIENT)
		pat.color_at = gradient_pattern;
	return (pat);
}


