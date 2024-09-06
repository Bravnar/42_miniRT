#include "main.h"

t_tup	str_to_vector(char *str)
{
	char	**str_split;
	t_tup	ret;
	bool	check_x;
	bool	check_y;
	bool	check_z;

	str_split = ft_split(str, ',');
	ret = vector(ft_strtod(str_split[0]),
			ft_strtod(str_split[1]),
			ft_strtod(str_split[2]));
	check_x = ret.x >= -1.0 && ret.x <= 1.0;
	check_y = ret.y >= -1.0 && ret.y <= 1.0;
	check_z = ret.z >= -1.0 && ret.z <= 1.0;
	ft_free_arr(str_split);
	if (!check_x || !check_y || !check_z)
		err_template("Vector out of range", str);
	return (ret);
}

t_tup	str_to_point(char *str)
{
	char	**str_split;
	t_tup	ret;

	str_split = ft_split(str, ',');
	ret = point(ft_strtod(str_split[0]),
			ft_strtod(str_split[1]),
			ft_strtod(str_split[2]));
	ft_free_arr(str_split);
	return (ret);
}

t_color	color_split(char *color_str)
{
	t_color	ret;
	char **color_split;
	int	r;
	int	g;
	int	b;

	color_split = ft_split(color_str, ',');
	r = ft_strtod(color_split[0]);
	g = ft_strtod(color_split[1]);
	b = ft_strtod(color_split[2]);
	ret = color(r, g, b);
	ft_free_arr(color_split);
	return (ret);
}

void	set_view_cam(t_cam *cam, t_rwin res)
{
	t_view_cam	view;

	view.hsize = res.x;
	view.vsize = res.y;
	view.fov = cam->fov * (PI / 180);
	calc_pixel_size(&view);
	view.transf_matrix = view_transform(cam->point,
			cam->vector, vector(0.0, 1.0, 0.0));
	cam->view = view;
}

t_cam	fetch_cam(t_parse **head, t_rwin res)
{
	t_parse *tmp;
	t_cam	cam;

	tmp = *head;
	while (tmp)
	{
		if (tmp->type == CAMERA)
		{
			cam.point = str_to_point(tmp->line_split[0]);
			cam.vector = str_to_vector(tmp->line_split[1]);
			cam.fov = ft_strtod(tmp->line_split[2]);
			if (cam.fov < 0.0 || cam.fov > 180.0)
				err_template(M_C_FOV_RANGE, tmp->line);
			set_view_cam(&cam, res);
			break ;
		}
		tmp = tmp->next;
	}
	return (cam);
}

t_amb	fetch_amb(t_parse **head)
{
	t_parse *tmp;
	t_amb	amb;

	tmp = *head;
	while (tmp)
	{
		if (tmp->type == AMBIENT)
		{
			amb.ratio = ft_strtod(tmp->line_split[0]);
			if (amb.ratio < 0.0 || amb.ratio > 1.0)
				err_template("AMB ratio out of range", tmp->line);
			amb.rgb = color_split(tmp->line_split[1]);
			break ;
		}
		tmp = tmp->next;
	}
	return (amb);
}

void	check_res_limits(t_rwin res, char *line)
{
	if (res.x < 0 || res.y < 0)
		err_template("Resolution too small", line);
	if (res.x > WIN_X_MAX || res.y > WIN_Y_MAX)
		err_template("Resolution too large", line);
}

t_rwin	fetch_res(t_parse **head)
{
	t_parse *tmp;
	t_rwin	res;

	tmp = *head;
	res.x = WIN_X_DEFAULT;
	res.y = WIN_Y_DEFAULT;
	while (tmp)
	{
		if (tmp->type == WINDOW)
		{
			res.x = ft_atoi(tmp->line_split[0]);
			res.y = ft_atoi(tmp->line_split[1]);
			check_res_limits(res, tmp->line);
			break ;
		}
		tmp = tmp->next;
	}
	return (res);
}
