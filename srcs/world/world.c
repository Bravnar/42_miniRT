#include "main.h"

void	my_draw_sphere(t_main *rt)
{
	double	wall_size;
	double	wall_z;
	double	half;
	int		win_x;
	int		win_y;
	t_obj	sphere[3];
	int		y;
	int		x;

	y = 0;
	x = 0;
	win_x = get_scene_win()->x;
	win_y = get_scene_win()->y;
	sphere[0] = *get_scene()->obj_list;
	sphere[1] = *get_scene()->obj_list->next;
	sphere[2] = *get_scene()->obj_list->next->next;

	while (y < win_y)
	{
		win_y 
	}
}