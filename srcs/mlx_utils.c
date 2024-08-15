#include "main.h"

void	my_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < mlx->win_x && y >= 0 && y < mlx->win_y)
	{
		dst = mlx->img_data + (y * mlx->size_line + x * \
		(mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_rectangle(t_main *rt)
{
	int	i;
	int	j;

	j = rt->rect.y;
	while (j < rt->rect.y + rt->rect.height)
	{
		i = rt->rect.x;
		while (i < rt->rect.x + rt->rect.width)
		{
			my_pixel(&rt->mlx, i, j, rt->rect.color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window \
			(rt->mlx.mlx_ptr, rt->mlx.win_ptr, rt->mlx.img_ptr, 0, 0);
}

/* void	redraw(t_main *rt)
{
	if (rt->mlx.img_ptr != NULL)
		mlx_destroy_image(rt->mlx.mlx_ptr, rt->mlx.img_ptr);
	rt->mlx.img_ptr = \
		mlx_new_image(rt->mlx.mlx_ptr, rt->mlx.win_x, rt->mlx.win_y);
	rt->mlx.img_data = \
		mlx_get_data_addr(rt->mlx.img_ptr, &rt->mlx.bits_per_pixel, \
		&rt->mlx.size_line, &rt->mlx.endian);
	draw_rectangle(rt);
	mlx_put_image_to_window \
			(rt->mlx.mlx_ptr, rt->mlx.win_ptr, rt->mlx.img_ptr, 0, 0);
}
 */