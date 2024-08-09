#include "main.h"

void	render(t_view_cam cam, t_world w, t_main *rt)
{
	int		y;
	int		x;
	t_ray	new;

	y = 0;
	while (y < cam.vsize - 1)
	{
		x = 0;
		while (x < cam.hsize - 1)
		{
			new = ray_for_pixel(cam, x, y);
			// if (x == 5 && y == 5)
			// {
			// 	printf("pixel at [%d],[%d]:\n", x, y);
			// 	print_color(color_at(w, new));
			// 	return ;
			// }
			my_pixel(&rt->mlx, x, y, color_at(w, new).hex);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win_ptr, rt->mlx.img_ptr, 0, 0);
}

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

void	print_view_cam(t_view_cam cam)
{
	printf("hsize: %f\n", cam.hsize);
	printf("vsize: %f\n", cam.vsize);
	printf("fov: %.2f\n", cam.fov);
	printf("aspect ratio: %f\n", cam.aspect);
	printf("half_view: %.2f\n", cam.half_view);
	printf("half_width: %.2f\n", cam.half_width);
	printf("half_height: %.2f\n", cam.half_height);
	printf("pixel_size: %.2f\n", cam.pixel_size);
	printf("tranform-------------:\n");
	print_matrix(cam.transf_matrix, 4);
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

t_view_cam	init_camera(double hsize, double vsize, double fov)
{
	t_view_cam	camera;

	camera.hsize = hsize;
	camera.vsize = vsize;
	camera.fov = fov;
	calc_pixel_size(&camera);
	camera.transf_matrix = identity();
	return (camera);
}

t_matrix	view_transform(t_tup from, t_tup to, t_tup up)
{
	t_tup		forward;
	t_tup		upn;
	t_tup		left;
	t_tup		true_up;
	t_matrix	orientation;

	forward = vector_norm(tuple_sub(to, from));
	upn = vector_norm(up);
	left = vector_cross(forward, upn);
	true_up = vector_cross(left, forward);
	orientation = identity();
	orientation.M[0][0] = left.x;
	orientation.M[0][1] = left.y;
	orientation.M[0][2] = left.z;
	orientation.M[1][0] = true_up.x;
	orientation.M[1][1] = true_up.y;
	orientation.M[1][2] = true_up.z;
	orientation.M[2][0] = -forward.x;
	orientation.M[2][1] = -forward.y;
	orientation.M[2][2] = -forward.z;
	return (matrix_mult(orientation,
			translation_matrix(-from.x, -from.y, -from.z)));
}
