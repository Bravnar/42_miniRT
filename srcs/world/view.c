#include "main.h"

t_ray	ray_for_pixel(t_view_cam cam, double px, double py)
{
	t_cam_ray	r;
	t_tup		origin;
	t_tup		direction;

	r.xoffset = (px + 0.5) * cam.pixel_size;
	r.yoffset = (py + 0.5) * cam.pixel_size;
	r.world_x = cam.half_width - r.xoffset;
	r.world_y = cam.half_height - r.yoffset;
	r.pixel = matrix_mult_tup(inverse(cam.transf_matrix, 4),
			point(r.world_x, r.world_y, -1));
	origin = matrix_mult_tup(inverse(cam.transf_matrix, 4),
			point(0, 0, 0));
	direction = vector_norm(tuple_sub(r.pixel, origin));
	return (ray_new(origin, direction));
}

void	calc_pixel_size(t_view_cam *cam)
{
	cam->half_view = tan(cam->fov / 2);
	cam->aspect = cam->hsize / cam->vsize;
	if (cam->aspect >= 1)
	{
		cam->half_width = cam->half_view;
		cam->half_height = cam->half_view / cam->aspect;
	}
	else
	{
		cam->half_width = cam->half_view * cam->aspect;
		cam->half_height = cam->half_view;
	}
	cam->pixel_size = (cam->half_width * 2) / cam->hsize;
}

t_matrix	view_transform(t_tup from, t_tup forward, t_tup up)
{
	t_tup		upn;
	t_tup		left;
	t_tup		true_up;
	t_matrix	orientation;

	upn = vector_norm(up);
	left = vector_cross(forward, upn);
	true_up = vector_cross(left, forward);
	orientation = identity();
	orientation.m[0][0] = left.x;
	orientation.m[0][1] = left.y;
	orientation.m[0][2] = left.z;
	orientation.m[1][0] = true_up.x;
	orientation.m[1][1] = true_up.y;
	orientation.m[1][2] = true_up.z;
	orientation.m[2][0] = -forward.x;
	orientation.m[2][1] = -forward.y;
	orientation.m[2][2] = -forward.z;
	return (matrix_mult(orientation,
			translation_matrix(-from.x, -from.y, -from.z)));
}
