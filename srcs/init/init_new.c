#include "main.h"

void	init_rwin(t_rwin *win)
{
	ft_bzero(win, sizeof(t_rwin));
}

void	init_amb(t_amb *amb)
{
	ft_bzero(amb, sizeof(t_amb));
}

void	init_cam(t_cam *cam)
{
	ft_bzero(cam, sizeof(t_cam));
}

void	init_light(t_light *light)
{
	ft_bzero(light, sizeof(t_light));
}

void	init_map(t_map *data)
{
	data->file.fd = -1;
	data->file.parse = NULL;
	data->file.is_valid = false;
	init_rwin(&data->win);
	init_amb(&data->amb);
	init_cam(&data->cam);
	init_light(&data->light);		//if bonus needs to be linked list!
	data->obj_list = NULL;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->win_x = 900;
	mlx->win_y = 550;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y, "miniRT");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, \
		&mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
}

t_main	*init_all(void)
{
	t_main	*main;

	main = malloc(sizeof(t_main));
	if (!main)
		return (NULL);
	init_map(&main->data);
	//init_mlx(&main->mlx);
	return (main);
}