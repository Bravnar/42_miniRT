#include "main.h"

t_color	color(int r, int g, int b)
{
	t_color	new;

	new.r = r;
	new.g = g;
	new.b = b;
	new.t = 255;
	return (new);
}

void	add_hex_color(t_color *c)
{
	c->hex = (c->t << 24 | c->r << 16 | c->g << 8 | c->b);
}

