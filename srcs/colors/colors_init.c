#include "main.h"

t_color	color(double r, double g, double b)
{
	t_color	new;

	new.r = r;
	new.g = g;
	new.b = b;
	new.hex = nadd_hex_color(r, g, b);
	return (new);
}

void	add_hex_color(t_color *c)
{
	if (c->r > 255)
		c->r = 255;
	if (c->g > 255)
		c->g = 255;
	if (c->b > 255)
		c->b = 255;
	c->hex = ((int) c->r << 16 | \
			(int) c->g << 8 | \
			(int) c->b);
}

int	nadd_hex_color(int r, int g, int b)
{
	int	hex;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	hex = (r << 16 | \
			g << 8 | \
			b);
	return (hex);
}

void	print_color(t_color c)
{
	printf("(%.4f, %.4f, %.4f) ", c.r / 255, c.g / 255, c.b / 255);
	printf("\n");
}
