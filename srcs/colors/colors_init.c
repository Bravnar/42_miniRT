#include "main.h"

void	add_hex_color(t_color *c);

t_color	color(double r, double g, double b)
{
	t_color	new;

	new.r = r;
	new.g = g;
	new.b = b;
	new.t = 255;
	add_hex_color(&new);
	return (new);
}

void	add_hex_color(t_color *c)
{
	c->hex = ((int)c->t << 24 | \
			(int) c->r << 16 | \
			(int) c->g << 8 | \
			(int) c->b);
}

t_color	black(void)
{
	return (color(0, 0, 0));
}

void	print_color(t_color c)
{
	printf("(%f, %f, %f) ", c.r / 255, c.g / 255, c.b / 255);
}
