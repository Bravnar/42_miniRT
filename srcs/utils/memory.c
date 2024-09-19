/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:58:48 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/19 17:41:24 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->light)
		free_light_nodes(map->light);
	if (map->obj_list)
		free_obj_nodes(map->obj_list);
	if (map->file.parse != NULL)
		free_nodes(map->file.parse);
	free(map);
}

void	free_rt(t_mrt *mrt)
{
	if (mrt->mlx.img_ptr)
		mlx_destroy_image(mrt->mlx.mlx_ptr, mrt->mlx.img_ptr);
	if (mrt->mlx.win_ptr)
		mlx_destroy_window(mrt->mlx.mlx_ptr, mrt->mlx.win_ptr);
	if (mrt->mlx.mlx_ptr)
		mlx_destroy_display(mrt->mlx.mlx_ptr);
	if (mrt->mlx.mlx_ptr)
		free(mrt->mlx.mlx_ptr);
	free_map(mrt->map);
	free(mrt);
	mrt = NULL;
}

void	free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}
