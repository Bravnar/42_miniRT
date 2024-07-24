#include "main.h"

void	init_rect(t_rect *rect)
{
	rect->x = 100;
	rect->y = 100;
	rect->height = 200;
	rect->width = 200;
	rect->color = 0xffffff;
}

void	init_mlx(t_mlx  *mlx)
{
	mlx->win_x = 900;
	mlx->win_y = 550;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y, "miniRT");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, \
		&mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
}

t_main   *init_main(void)
{
	t_main  *rt;
	
  rt = malloc(sizeof(t_main));
	if (!rt)
		return (NULL);
	init_rect(&rt->rect);
	return (rt);
}
