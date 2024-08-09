#include "main.h"

void	add_hex_color(t_color *c);
int		nadd_hex_color(int r, int g, int b, int t);

t_color	color(double r, double g, double b)
{
	t_color	new;

	new.r = r;
	new.g = g;
	new.b = b;
	new.t = 255;
	// add_hex_color(&new);
	new.hex = nadd_hex_color(r, g, b, new.t);
	return (new);
}

void	add_hex_color(t_color *c)
{
	c->hex = ((int)c->t << 24 | \
			(int) c->r << 16 | \
			(int) c->g << 8 | \
			(int) c->b);
}

int	nadd_hex_color(int r, int g, int b, int t)
{
	int	hex;
	hex = (t << 24 | \
			r << 16 | \
			g << 8 | \
			b);
	return (hex);
}

t_color	black(void)
{
	return (color(0, 0, 0));
}

void	print_color(t_color c)
{
	printf("(%f, %f, %f) ", c.r / 255, c.g / 255, c.b / 255);
	printf("\n");
}
