#include "main.h"

/* void	setup_world(t_world *world)
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
} */

t_inter	app_intersect(t_inter *xs, t_inter *new)
{
	t_inter ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret.count = xs->count + new->count;
	ret.i = malloc(ret.count * sizeof(t_inter));
	if (!ret.i)
	{
		ret.count = 0;
		return (ret);
	}
	while (j < xs->count)
		ret.i[i++] = xs->i[j++];
	j = 0;
	while (j < new->count)
		ret.i[i++] = new->i[j++];
	if (xs->count)
		free(xs->i);
	if (new->count)
		free(new->i);
	return ret;
}

t_inter	intersect_world(t_world w, t_ray r)
{
	t_obj	*tmp;
	t_inter	xs;
	t_inter	sphere_tmp;

	xs.count = 0;
	tmp = w.shapes;
	sphere_tmp.count = 0;
	sphere_tmp.i = NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->get_name(tmp), "Sphere"))
		{
			sphere_tmp = intersect_sphere(r, tmp);
			xs = app_intersect(&xs, &sphere_tmp);
		}
		tmp = tmp->next;
	}
	return (xs);
}

t_world	create_world(void)
{
	t_world	w;

	w.light = get_scene()->light;
	w.shapes = get_scene()->obj_list;
	return w;
}
