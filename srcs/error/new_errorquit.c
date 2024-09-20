#include "main.h"

void	list_errors(void)
{

}

void	clean_pre_fetch(t_mrt *mrt)
{
	free_nodes(mrt->map->file.parse);
	free(mrt);
	exit(1);
}

void	clean_post_fetch(t_mrt *mrt)
{
	free_nodes(mrt->map->file.parse);
	free_light_nodes(mrt->map->light);
	free_obj_nodes(mrt->map->obj_list);
	free(mrt);
	exit(1);
	
}

void	clean_end(t_mrt	*mrt)
{
	free_nodes(mrt->map->file.parse);
	free_light_nodes(mrt->map->light);
	free_obj_nodes(mrt->map->obj_list);
	free(mrt);
	exit(1);
}