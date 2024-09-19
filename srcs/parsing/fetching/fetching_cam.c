#include "main.h"

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
	t_parse	*tmp;
	t_cam	cam;

	tmp = *head;
	cam.point = point(0, 0, 0);
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
