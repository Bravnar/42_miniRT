#include "main.h"

void	setup_world(t_world *world)
{
	t_map	*scene;
	scene = get_scene();
	
	world->aspect_ratio = (double)scene->win.x / (double)scene->win.y;
	world->hfov_radians = scene->cam.fov * PI / 180;
	world->view_width = 2.0 * tan(world->hfov_radians / 2.0);
	world->view_height = world->view_width / world->aspect_ratio;
	world->limit_x = scene->win.x;
	world->limit_y = scene->win.y;
	world->x = -1;
	world->y = -1;
	world->cam_pos = scene->cam.point;
	world->cam_dir = scene->cam.vector;
}
