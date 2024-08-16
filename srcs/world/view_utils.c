#include "main.h"

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

