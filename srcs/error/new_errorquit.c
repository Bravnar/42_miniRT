/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_errorquit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:56:50 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 15:58:22 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Frees the memory allocated for the map structure.
 *
 * This function releases all resources associated with the given map structure.
 *
 * @param map Pointer to the map structure to be freed.
 */
void	free_map(t_map *map)
{
	t_errors	*err;

	err = *get_errors();
	if (err)
		free_errors();
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

/**
 * @brief Frees the resources associated with the given miniRT structure.
 *
 * This function is responsible for releasing all the memory and resources
 * allocated for the `t_mrt` structure. It ensures that there are no memory
 * leaks by properly deallocating any dynamically allocated memory within
 * the structure.
 *
 * @param mrt A pointer to the `t_mrt` structure to be freed.
 */
void	free_rt(t_mrt *mrt)
{
	t_errors	*err;

	err = *get_errors();
	if (err)
		free_errors();
	if (mrt->mlx.img_ptr)
		mlx_destroy_image(mrt->mlx.mlx_ptr, mrt->mlx.img_ptr);
	if (mrt->mlx.win_ptr)
		mlx_destroy_window(mrt->mlx.mlx_ptr, mrt->mlx.win_ptr);
	/* if (mrt->mlx.mlx_ptr)
		mlx_destroy_display(mrt->mlx.mlx_ptr); */
	if (mrt->mlx.mlx_ptr)
		free(mrt->mlx.mlx_ptr);
	free_map(mrt->map);
	free(mrt);
	mrt = NULL;
	exit(1);
}

/**
 * @brief Cleans up resources allocated during the pre-fetch phase.
 *
 * This function is responsible for releasing any resources that were
 * allocated during the pre-fetch phase of the program. It ensures that
 * there are no memory leaks or dangling pointers before the program
 * proceeds to the next phase.
 *
 * @param mrt A pointer to the main structure containing all necessary
 *            data and resources for the program.
 */
void	clean_pre_fetch(t_mrt *mrt)
{
	t_errors	*err;

	err = *get_errors();
	if (err)
		free_errors();
	free_nodes(mrt->map->file.parse);
	free(mrt);
	exit(1);
}

/**
 * @brief Cleans up resources after fetching data.
 *
 * This function is responsible for performing any necessary cleanup
 * operations after data has been fetched. It ensures that all allocated
 * resources are properly released and any temporary data is cleared.
 *
 * @param mrt Pointer to the main structure containing all relevant data.
 */
void	clean_post_fetch(t_mrt *mrt)
{
	t_errors	*err;

	err = *get_errors();
	if (err)
		free_errors();
	free_map(mrt->map);
	free(mrt);
	exit(1);
}
