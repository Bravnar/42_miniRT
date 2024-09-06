#include "main.h"

t_rwin	*get_scene_win(void)
{
	return (&get_map()->win);
}

t_amb	*get_scene_amb(void)
{
	return (&get_map()->amb);
}

t_cam	*get_scene_cam(void)
{
	return (&get_map()->cam);
}

t_light	**get_scene_light(void)
{
	return (&get_map()->light);
}

t_obj	**get_scene_objs(void)
{
	return (&get_map()->obj_list);
}
