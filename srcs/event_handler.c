#include "main.h"

int	close_win(void *param)
{
	t_main	*rt;

	rt = (t_main *)param;
	if (rt->mlx.win_ptr)
	{
		mlx_destroy_image(rt->mlx.mlx_ptr, rt->mlx.img_ptr);
		mlx_destroy_window(rt->mlx.mlx_ptr, rt->mlx.win_ptr);
		free(rt);
		exit(0);
	}
	return (0);
}

int	keyboard(int keycode, t_main *rt)
{
	printf("key pressed: %d\n", keycode);
	if (keycode == ESC || keycode == Q_KEY)
	{
		if (rt->mlx.win_ptr)
		{
			mlx_destroy_image(rt->mlx.mlx_ptr, rt->mlx.img_ptr);
			mlx_destroy_window(rt->mlx.mlx_ptr, rt->mlx.win_ptr);
			free(rt);
			exit(0);
		}
	}
	return (0);
}

int	mouse_down(int keycode, int x, int y, t_main *rt)
{
	if (keycode == 1)
		draw_fdf_sphere();
	return (0);
}


void	handle_events(t_main *rt)
{
	mlx_hook(rt->mlx.win_ptr, 17, 0, close_win, rt);
	mlx_hook(rt->mlx.win_ptr, 2, 1L<<0, keyboard, rt);
	mlx_hook(rt->mlx.win_ptr, 4, 0, mouse_down, rt);
	// mlx_hook(rt->mlx.win_ptr, 5, 0, mouse_up, rt);
	// mlx_hook(rt->mlx.win_ptr, 6, 0, mouse_move, rt);
}