#include "main.h"

void	add_hex_color(t_color *c);

t_color	color(int r, int g, int b)
{
	t_color	new;

	new.r = (double)(unsigned char)r;
	new.g = (double)(unsigned char)g;
	new.b = (double)(unsigned char)b;
	new.t = 255;
	add_hex_color(&new);
	return (new);
}

void	add_hex_color(t_color *c)
{
	c->hex = ((int)c->t << 24 | (int) c->r << 16 | (int) c->g << 8 | (int) c->b);
}

t_color	black(void)
{
	return (color(0, 0, 0));
}

void	print_color(t_color c)
{
	printf("Color: (%f, %f, %f)\n", c.r/255, c.g/255, c.b/255);
}
