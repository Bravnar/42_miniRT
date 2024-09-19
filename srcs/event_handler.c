#include "main.h"

void	redraw(t_mrt *rt, t_world w)
{
	if (rt->mlx.img_ptr != NULL)
		mlx_destroy_image(rt->mlx.mlx_ptr, rt->mlx.img_ptr);
	rt->mlx.img_ptr = \
		mlx_new_image(rt->mlx.mlx_ptr, rt->mlx.win_x, rt->mlx.win_y);
	rt->mlx.img_data = \
		mlx_get_data_addr(rt->mlx.img_ptr, &rt->mlx.bits_per_pixel, \
		&rt->mlx.size_line, &rt->mlx.endian);
	get_scene_cam()->view.transf_matrix = view_transform(get_scene_cam()->point,
							get_scene_cam()->vector,
							point(0, 1, 0));
	render(get_scene_cam()->view, w, rt);
	mlx_put_image_to_window \
			(rt->mlx.mlx_ptr, rt->mlx.win_ptr, rt->mlx.img_ptr, 0, 0);
}

int	close_win(void *param)
{
	t_mrt	*rt;

	rt = (t_mrt *)param;
	if (rt->mlx.win_ptr)
	{
		free_rt(rt);
		exit(0);
	}
	return (0);
}

int	keyboard(int keycode, t_mrt *rt)
{
	t_world	w;

	w = create_world();
	(void)	w;
	printf("key pressed: %d\n", keycode);
	if (keycode == ESC || keycode == Q_KEY)
	{
		if (rt->mlx.win_ptr)
		{
			free_rt(rt);
			exit(0);
		}
	}
	if (keycode == LEFT)
		printf("Pressing LEFT\n");
	else if (keycode == RIGHT)
		printf("Pressing RIGHT\n");
	else if (keycode == DOWN)
		printf("Pressing DOWN\n");
	else if (keycode == UP)
		printf("Pressing UP\n");
	else if (keycode == P_KEY)
		print_scene_details();
	return (0);
}

void	handle_events(t_mrt *rt)
{
	mlx_hook(rt->mlx.win_ptr, 17, 0, close_win, rt);
	mlx_hook(rt->mlx.win_ptr, 2, 1L << 0, keyboard, rt);
	// mlx_hook(rt->mlx.win_ptr, 4, 0, mouse_down, rt);
	// mlx_hook(rt->mlx.win_ptr, 5, 0, mouse_up, rt);
	// mlx_hook(rt->mlx.win_ptr, 6, 0, mouse_move, rt);
}
