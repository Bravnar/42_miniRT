/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:05:08 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/20 10:05:11 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	close_win(void *param)
{
	t_mrt	*rt;

	rt = (t_mrt *)param;
	if (rt->mlx.win_ptr)
	{
		free_rt(rt);
	}
	return (0);
}

void	do_unlocked(int keycode, t_mrt *rt, t_world w)
{
	if (keycode == LEFT)
	{
		get_map()->cam.point.x -= 3.0;
		get_map()->cam.point.z += 2.0;
		get_map()->cam.vector.x += 0.2;
		get_map()->cam.vector.z -= 0.2;
	}
	else if (keycode == RIGHT)
	{
		get_map()->cam.point.x += 3.0;
		get_map()->cam.point.z += 2.0;
		get_map()->cam.vector.x -= 0.2;
		get_map()->cam.vector.z -= 0.2;
	}
	else if (keycode == DOWN)
		get_map()->cam.point.y -= 2.0;
	else if (keycode == UP)
		get_map()->cam.point.y += 2.0;
	redraw(rt, w);
}

void	do_keys(int keycode, t_mrt *rt, t_world w)
{
	if (keycode == U_KEY)
		rt->is_unlocked = !rt->is_unlocked;
	printf("Is unlocked: %d\n", rt->is_unlocked);
	if (!rt->is_unlocked)
	{
		if (keycode == LEFT)
			printf("Pressing LEFT\n");
		else if (keycode == RIGHT)
			printf("Pressing RIGHT\n");
		else if (keycode == DOWN)
			printf("Pressing DOWN\n");
		else if (keycode == UP)
			printf("Pressing UP\n");
	}
	else if (rt->is_unlocked && (keycode == LEFT || \
		keycode == RIGHT || keycode == UP || keycode == DOWN))
		do_unlocked(keycode, rt, w);
}

int	keyboard(int keycode, t_mrt *rt)
{
	t_world	w;

	w = create_world();
	(void) w;
	printf("key pressed: %d\n", keycode);
	if (keycode == ESC || keycode == Q_KEY)
	{
		if (rt->mlx.win_ptr)
		{
			free_rt(rt);
		}
	}
	do_keys(keycode, rt, w);
	return (0);
}

void	handle_events(t_mrt *rt)
{
	mlx_hook(rt->mlx.win_ptr, 17, 0, close_win, rt);
	mlx_hook(rt->mlx.win_ptr, 2, 1L << 0, keyboard, rt);
}

// mlx_hook(rt->mlx.win_ptr, 4, 0, mouse_down, rt);
// mlx_hook(rt->mlx.win_ptr, 5, 0, mouse_up, rt);
// mlx_hook(rt->mlx.win_ptr, 6, 0, mouse_move, rt);
