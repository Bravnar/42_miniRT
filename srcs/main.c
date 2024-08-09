#include "main.h"

#define SPHERE_RADIUS 100
#define NUM_LATS 10
#define NUM_LONGS 10

t_tup **create_sphere(double radius, int num_lats, int num_longs) 
{
	t_tup	**vertices;
	int		i;
	int		j;

	i = -1;
	j = -1;

	vertices = malloc((num_lats + 1) * sizeof(t_tup *));
	if (!vertices)
		return (NULL);
	while (++i <= num_lats)
	{
		vertices[i] = malloc((num_longs + 1) * sizeof(t_tup));
		double lat = PI * (-0.5 + (double)i / num_lats);
		j = -1;
		while (++j <= num_longs)
		{
			double lon = 2 * PI * (float)j / num_longs;
			vertices[i][j].x = radius * cos(lat) * cos(lon);
			vertices[i][j].y = radius * cos(lat) * sin(lon);
			vertices[i][j].z = radius * sin(lat);
		}
	}
	return vertices;
}

void	draw_fdf_sphere()
{

}

void	draw_line(t_main *rt, t_tup start, t_tup end)
{
	float	dx;
	float	dy;
	float	max;

	dx = end.x - start.x;
	dy = end.y - start.y;
	max = max_point(fabsf(dx), fabsf(dy));
	dx /= max;
	dy /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		my_pixel(&rt->mlx, start.x, start.y, 0xffffff);
		start.x += dx;
		start.y += dy;
	}
}

void	game_loop(t_main *rt)
{
	init_mlx(&rt->mlx);
	handle_events(rt);
	mlx_loop(rt->mlx.mlx_ptr);
}

int main(int ac, char **av)
{
	t_main  *rt;
	t_tup	**vertices = create_sphere(SPHERE_RADIUS, NUM_LATS, NUM_LONGS);
	

	if (ac != 2)
		return (0);
	rt = init_all(av[1]);
	if (!rt)
		exit(1);
	game_loop(rt);
	free(rt);
}

