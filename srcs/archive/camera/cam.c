#include "main.h"

static void	get_cam_point(char *str)
{
	char	**tup_split;
	t_tup	*cam_point;

	cam_point = &get_scene()->cam.point;
	tup_split = ft_split(str, ',');
	*cam_point = point(ft_strtod(tup_split[0]),
			ft_strtod(tup_split[1]),
			ft_strtod(tup_split[2]));
	ft_free_arr(tup_split);
}

static void	get_cam_vector(char *str)
{
	char	**tup_split;
	t_tup	tmp;
	t_cam	*cam;

	cam = &get_scene()->cam;
	tup_split = ft_split(str, ',');
	cam->vector = vector(ft_strtod(tup_split[0]),
			ft_strtod(tup_split[1]),
			ft_strtod(tup_split[2]));
	tmp = get_scene()->cam.vector;
	if (tmp.x < -1.0 || tmp.x < -1.0 || tmp.z < -1.0)
	{
		printf("outside of range (-1.0)\n");
		exit (1);
	}
	if (tmp.x > 1.0 || tmp.x > 1.0 || tmp.z > 1.0)
	{
		printf("outside of range (1.0)\n");
		exit (1);
	}
	ft_free_arr(tup_split);
}

void	init_view(t_cam *cam)
{
	t_view_cam	view;

	view.hsize = get_scene_win()->x;
	view.vsize = get_scene_win()->y;
	view.fov = cam->fov * (PI / 180);
	calc_pixel_size(&view);
	view.transf_matrix = view_transform(cam->point,
			cam->vector,
			vector(0.0, 1.0, 0.0));
	cam->view = view;
}

void	populate_cam(void)
{
	t_parse	*tmp;
	t_cam	*cam;

	cam = get_scene_cam();
	tmp = get_scene()->file.parse;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line_split[0], "C"))
		{
			get_cam_point(tmp->line_split[1]);
			get_cam_vector(tmp->line_split[2]);
			cam->fov = ft_atoi(tmp->line_split[3]);
			if (cam->fov < 0 || cam->fov > 180)
				err_handler(C_FOV_RANGE);
			init_view(cam);
			break ;
		}
		tmp = tmp->next;
	}
}
