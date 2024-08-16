#include "main.h"

// STAN TESTER MAIN
int main(int ac, char **av)
{
	t_main  *rt;
	int		debug = 0;

	if (ac > 3)
		return (0);
	if (ac == 3)
		debug = 1;
	rt = init_all(av[1]);
	if (!rt)
		exit(1);
	populate_scene_struct(av[1], get_scene());
	print_color(get_scene()->light->intensity);
	//print_scene_details();
	//test_gameloop(rt);

	// RUNS THE RENDER TEST WITH GIVEN .RT FILE CHECK test_scene_render(rt, av[1])
	if (!debug)
	{
		test_scene_render(rt, av[1]);
		return (0);
	}
	/*
	printf("Creating world -------------------------------------------:\n");
	t_world	w;
	w = create_world();
	t_ray	r = ray_new(point(0, 0, -5), vector(0, 0, 1)); // 0,0,-5 | 0,0,0
	t_inter	xs = intersect_world(w, r);


	printf("Calculating intersection ---------------------------------:\n");
	printf("xs: count = %d\n", xs.count);
	int	i = -1;
	while (++i < xs.count)
		printf("xs[%d].t = %f\n", i, xs.i[i].t);
	w.shapes->material.diffuse = 0.7;
	w.shapes->material.specular = 0.2;
	w.shapes->next->material.diffuse = 0.9; // 0.7 for sphere00 | 0.9 for sphere01
	w.shapes->next->material.specular = 0.9; // 0.2 for sphere00 | 0.9 for sphere01
	t_intersection test = intersection(4, w.shapes); // 4, w.shapes | 0.6m w.shapes->next
	// t_intersection test = hit(xs);
	printf("test result: %f\n", test.t);


	printf("Testing computations -------------------------------------:\n");
	t_comps test_comp = prepare_comp(test, r);
	print_tuple(test_comp.point);
	print_tuple(test_comp.eyev);
	printf("test_comp result: %d\n", test_comp.is_inside);
	print_tuple(test_comp.normalv);

	printf("Testing shade_hit ----------------------------------------:\n");

	t_color	c = shade_hit(w, test_comp);
	print_color(c);

	printf("\nTesting color_at() ---------------------------------------:\n");
	t_color color_at_test = color_at(w, r);
	print_color(color_at_test);

	printf("\nTesting color_at() with two objects ----------------------:\n");
	w.shapes->material.amb = 1;
	w.shapes->next->material.amb = 1;
	r = ray_new(point(0, 0, 0.75), vector(0, 0, -1));
	color_at_test = color_at(w, r);
	print_color(color_at_test);

	printf("\nEND OF WORLD TESTS ---------------------------------------:\n");

	printf("\nSTART OF VIEW TESTS -------------------------------------:\n");

	printf("\nTest: The transformation matrix for the default orientation:\n");
	t_tup	from = point(0, 0, 0);
	t_tup	to = point(0, 0, -1);
	t_tup	up = vector(0, 1, 0);
	t_matrix	ret = view_transform(from, to, up);
	print_matrix(ret, 4);

	printf("\nTest: A view transformation matrix looking in positive z direction\n");
	from = point(0, 0, 0);
	to = point(0, 0, 1);
	up = vector(0, 1, 0);
	ret = view_transform(from, to, up);
	print_matrix(ret, 4);
	printf(" -------------------------------------------------------------\n");
	print_matrix(scaling_matrix(-1, 1, -1), 4);

	printf("\nTest: The view transformaton moves the world\n");
	from = point(0, 0, 8);
	to = point(0, 0, 0);
	up = vector(0, 1, 0);
	ret = view_transform(from, to, up);
	print_matrix(ret, 4);
	printf(" -------------------------------------------------------------\n");
	print_matrix(translation_matrix(0, 0, -8), 4);

	printf("\nAn arbitrary view transformation\n");
	from = point(1, 3, 2);
	to = point(4, -2, 8);
	up = vector(1, 1, 0);
	ret = view_transform(from, to, up);
	print_matrix(ret, 4);
	printf(" -------------------------------------------------------------\n");

	printf("\nSTART OF CAMERA TESTS -------------------------------------:\n");

	t_view_cam	cam;
	cam = init_camera(200, 125, PI/2);
	print_view_cam(cam);

	printf("\nTest 1 ----------------------------------------------------:\n");
	cam = init_camera(201, 101, PI/2);
	t_ray	cam_r = ray_for_pixel(cam, 100, 50);
	print_ray(cam_r);
	printf("\nTest 2 ----------------------------------------------------:\n");
	cam = init_camera(201, 101, PI/2);
	cam_r = ray_for_pixel(cam, 0, 0);
	print_ray(cam_r);
	printf("\nTest 3 ----------------------------------------------------:\n");
	cam = init_camera(201, 101, PI/2);
	cam.transf_matrix = matrix_mult(rotation_y(45), translation_matrix(0, -2, 5));
	cam_r = ray_for_pixel(cam, 100, 5);
	print_ray(cam_r);

	// printf("\nRendering a world with a camera\n");
	// cam = init_camera(11, 11, PI/2);
	// from = point(0, 0, -5);
	// to = point(0, 0, 0);
	// up = vector(0, 1, 0);
	// cam.transf_matrix = view_transform(from, to, up);
	// render(cam, w, rt);

	// END ------------------------------------------------------------//
	free(xs.i);*/
	//game_loop(rt);
	lighting_test_battery();
	ray_test_battery();
	hit_test_battery();
	free(rt);
}

