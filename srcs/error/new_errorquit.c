#include "main.h"

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
	if (mrt->mlx.mlx_ptr)
		mlx_destroy_display(mrt->mlx.mlx_ptr);
	if (mrt->mlx.mlx_ptr)
		free(mrt->mlx.mlx_ptr);
	free_map(mrt->map);
	free(mrt);
	mrt = NULL;
	exit(1);
}

void	list_errors(void)
{

}

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
