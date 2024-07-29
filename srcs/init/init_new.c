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
	init_light(data->light);		//if bonus needs to be linked list!
	data->obj_list = NULL;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->win_x = 3840;
	mlx->win_y = 2160;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y, "miniRT");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, \
		&mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
}

t_map	*create_scene(char *file_name)
{
	static t_map	*scene;

	if (scene)
		return (scene);
	if (!file_name)
		return (NULL);
	scene = ft_calloc(1, sizeof(t_map));
	scene->win.x = 1920;
	scene->win.y = 1080;
	ft_bzero(&scene->file, sizeof(t_file));
	scene->file.fd = -1;
	scene->file.is_valid = true;
	ft_bzero(&scene->amb, sizeof(t_amb));
	ft_bzero(&scene->cam, sizeof(t_cam));
	scene->light = NULL;
	scene->obj_list = NULL;
	// populate_scene_struct(file_name, scene);
	// if (!scene->file.is_valid)
	// 	return (NULL);
	return(scene);
}

t_map	*get_scene(void)
{
	static t_map	*scene;

	if (!scene)
		scene = create_scene(NULL);
	return (scene);
}

t_main	*init_all(char *file_name)
{
	t_main	*main;

	main = malloc(sizeof(t_main));
	if (!main)
		return (NULL);
	main->data = create_scene(file_name);
	//init_mlx(&main->mlx);
	return (main);
}
