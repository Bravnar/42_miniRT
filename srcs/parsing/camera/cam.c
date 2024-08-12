#include "main.h"

static void	get_cam_point(char *str)
{
	char	**tup_split;

	tup_split = ft_split(str, ',');
	get_scene()->cam.point = point(ft_strtod(tup_split[0]),
							ft_strtod(tup_split[1]),
							ft_strtod(tup_split[2]));
	ft_free_arr(tup_split);
}

static void	get_cam_vector(char *str)
{
	char	**tup_split;
	t_tup	tmp;

	tup_split = ft_split(str, ',');
	get_scene()->cam.vector = vector(ft_strtod(tup_split[0]),
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

void	populate_cam(void)
{
	t_parse	*tmp;

	tmp = get_scene()->file.parse;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line_split[0], "C"))
		{
			get_cam_point(tmp->line_split[1]);
			get_cam_vector(tmp->line_split[2]);
			get_scene()->cam.fov = ft_atoi(tmp->line_split[3]);
			if (!get_scene()->cam.fov || get_scene()->cam.fov > 180)
				err_handler(C_FOV_RANGE);
			get_scene_cam()->view = init_camera(get_scene_win()->x,
									get_scene_win()->y,
									PI/3);
			break ;
		}
		tmp = tmp->next;
	}
}
