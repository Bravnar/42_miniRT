/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:05:41 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 09:07:26 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Closes the window and performs necessary cleanup.
 *
 * This function is typically called when the window close event is triggered.
 * It ensures that any resources allocated for the window are properly released.
 *
 * @param param A pointer to any additional parameters or context needed for
 *              closing the window. This can be NULL if no additional context
 *              is required.
 *
 * @return An integer status code indicating the result of the operation.
 *         Typically, 0 indicates success, while non-zero values indicate
 *         an error.
 */
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

/**
 * @brief Handles the event when an arrow key is released.
 *
 * This function is called when an arrow key (up, down, left, right) is released
 * and performs actions based on the keycode provided. It interacts
 * with the given miniRT runtime structure and the world structure.
 *
 * @param keycode The code of the arrow key that was released.
 * @param rt Pointer to the miniRT runtime structure.
 * @param w The world structure containing the scene data.
 */
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

/**
 * do_keys - Handles key events for the miniRT application.
 * @keycode: The code of the key that was pressed.
 * @rt: Pointer to the miniRT structure containing the application state.
 * @w: The world structure containing the scene data.
 *
 * This function processes the key events and updates the application state
 * accordingly. It is responsible for handling user input and modifying the
 * scene or application behavior based on the key pressed.
 */
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

/**
 * Handles keyboard events.
 *
 * @param keycode The code of the key that was pressed.
 * @param rt A pointer to the main structure of the miniRT program.
 * @return An integer indicating the result of the event handling.
 */
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
