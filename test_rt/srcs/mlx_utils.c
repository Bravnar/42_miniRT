/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:19:16 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 09:34:11 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	rt->map->cam.view.transf_matrix = view_transform(get_scene_cam()->point,
			get_scene_cam()->vector,
			point(0, 1, 0));
	render(get_scene_cam()->view, w, rt);
	mlx_put_image_to_window \
			(rt->mlx.mlx_ptr, rt->mlx.win_ptr, rt->mlx.img_ptr, 0, 0);
}

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