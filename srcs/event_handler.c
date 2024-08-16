#include "main.h"

void	redraw(t_main *rt, t_world w)
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
	t_world	w;

	w = create_world();
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
	if (keycode == LEFT)
	{
		get_scene_cam()->point.x -= 2.0;
		print_scene_details();
		redraw(rt, w);
	}
	else if (keycode == RIGHT)
	{
		get_scene_cam()->point.x += 2.0;
		print_scene_details();
		redraw(rt, w);
	}
	if (keycode == DOWN)
	{
		get_scene_cam()->point.y -= 2.0;
		print_scene_details();
		redraw(rt, w);
	}
	else if (keycode == UP)
	{
		get_scene_cam()->point.y += 2.0;
		print_scene_details();
		redraw(rt, w);
	}
	return (0);
}

void	handle_events(t_main *rt)
{
	mlx_hook(rt->mlx.win_ptr, 17, 0, close_win, rt);
	mlx_hook(rt->mlx.win_ptr, 2, 1L << 0, keyboard, rt);
	// mlx_hook(rt->mlx.win_ptr, 4, 0, mouse_down, rt);
	// mlx_hook(rt->mlx.win_ptr, 5, 0, mouse_up, rt);
	// mlx_hook(rt->mlx.win_ptr, 6, 0, mouse_move, rt);
}
