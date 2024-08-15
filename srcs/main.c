#include "main.h"

void	draw_circle(t_main *rt, t_obj *obj, int to_shear);

void	iterate_through_obj(t_obj **head, t_main *rt)
{
	t_obj	*tmp;
	int		i;

	i = 0;
	tmp = *head;
	while(tmp)
	{
		if (i == 7)
			draw_circle(rt, tmp, 1);
		else
			draw_circle(rt, tmp, 0);
		i++;
		tmp = tmp->next;
	}
}

void	game_loop(t_main *rt)
{
	init_mlx(&rt->mlx);
	iterate_through_obj(get_scene_objs(), rt);
	// draw_circle(rt);
	// draw_rectangle(rt);
	handle_events(rt);
	mlx_loop(rt->mlx.mlx_ptr);
}

void	draw_projectile(t_main *rt)
{
	t_env	environment;
	t_proj	projectile;
	t_color	col;
	t_tup	velocity;
	t_tup	start;

	start = point(0.0, 1.0, 0.0);
	velocity = vector_scalar_mult(vector_norm(vector(1, 1.8, 0)), 11.25);
	projectile = proj_new(start, velocity);
	environment = env_new(vector(0.0, -0.1, 0), vector(-0.01, 0, 0));
	col = color(255, 0, 0);
	add_hex_color(&col);
	//init_mlx(&rt->mlx);
	while (projectile.position.x < 900)
	{
		my_pixel(&rt->mlx, projectile.position.x, 550 - projectile.position.y, col.hex);
		my_pixel(&rt->mlx, projectile.position.x, projectile.position.y, 0x00ff00);
		my_pixel(&rt->mlx, projectile.position.x, (projectile.position.y*0.5), 0x0000ff);
		my_pixel(&rt->mlx, projectile.position.x, (550 - projectile.position.y) * 0.5, 0xffffff);
		projectile = tick(environment, projectile);
	}
	mlx_put_image_to_window \
			 (rt->mlx.mlx_ptr, rt->mlx.win_ptr, rt->mlx.img_ptr, 0, 0);
	handle_events(rt);
	mlx_loop(rt->mlx.mlx_ptr);
}

void	draw_watch(t_main *rt)
{
	t_env	environment;
	t_proj	projectile;
	t_tup	velocity;
	t_proj	temp;
	int		i;

	environment = env_new(vector(0, 0, 0), vector(0, 0 ,0));
	velocity = vector_scalar_mult(vector_norm(vector(1, 0, 0)), 150);
	projectile = proj_new(point(0, 0, 0), velocity);
	init_mlx(&rt->mlx);
	i = 0;
	while (i < 3600)
	{
		temp = tick(environment, projectile);
		my_pixel(&rt->mlx, temp.position.x + 450, 550 - temp.position.y - 275, 0x00ff00);
		velocity = scale(rotate(velocity, 0.1, 'z'), 1-1/3600, 0, 0);
		projectile = proj_new(point(0, 0, 0), velocity);
		i++;
	}
	mlx_put_image_to_window \
			 (rt->mlx.mlx_ptr, rt->mlx.win_ptr, rt->mlx.img_ptr, 0, 0);
	handle_events(rt);
	mlx_loop(rt->mlx.mlx_ptr);
}

t_obj	*search_obj_list(char *type)
{
	t_obj	**head;
	t_obj	*target;

	head = &get_scene()->obj_list;
	target = *head;
	while (target)
	{
		if (!ft_strcmp(target->get_name(target), type))
			return (target);
		target = target->next;
	}
	return (target);
}

t_color	color_at_hit(t_intersection hit, t_ray ray)
{
	t_color	col;
	t_tup	point;
	t_tup	normal;
	t_tup	eyev;

	point = position(ray, hit.t);
	normal = hit.shape->local_normal_at(hit.shape, point);
	eyev = tuple_neg(ray.direction);
	col = lighting(hit.shape->material, point, eyev, normal);
	add_hex_color(&col);
	return (col);
}

void	draw_circle(t_main *rt, t_obj *obj, int to_shear)
{
	int		y;
	int		x;
	int		pixels;
	double	wall_size;
	double	wall_z;
	double	half;
	double	pixel_size;
	double	world_y;
	double	world_x;
	t_ray	ray;
	t_inter	inter;
	t_obj	*sphere;

	wall_z = 5;
	wall_size = 2 * wall_z * tan(get_scene_cam()->fov / 2);
	half = wall_size / 2;
	pixels = 1600;
	pixel_size = wall_size / pixels;
	sphere = obj;
	if (to_shear)
	{
		double	sh[6] = {1, 0, 0, 0, 0, 0};
		sphere->transform(sphere, shearing_matrix(shear(sh)));
	}
	if (!sphere)
		return;
	y = -1;
	while (++y < pixels)
	{
		world_y = half - pixel_size * y;
		x = -1;
		while (++x < pixels)
		{
			world_x = -half + pixel_size * x;
			ray = ray_new(get_scene_cam()->point, vector_norm(tuple_sub(point(world_x, world_y, wall_z), get_scene_cam()->point)));
			inter = sphere->local_intersect(ray, sphere);
			if (inter.count)
			{
				t_intersection hit_info = hit(inter);
				if (hit_info.t != -1)
				{
					printf("Point: %d, %d\n", x, y);
					my_pixel(&rt->mlx, x, y, color_at_hit(hit_info, ray).hex);
				}
				free(inter.i);
				inter.i = NULL;
			}
		}
	}
	mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win_ptr, rt->mlx.img_ptr, 0, 0);
}

// int	main(void)
// {
// 	t_main  *rt;

// 	rt = init_all("test_rt/minimalist.rt");
// 	if (!rt)
// 		exit(1);
// 	draw_circle(rt);
// 	free(rt);

	/* populate_scene_struct("test_rt/minimalist.rt", get_scene());
	print_scene_details();
	//draw_projectile(rt);

	free(rt); */


	/* t_matrix A = {{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	}};

	t_matrix B = {{
		{-2, 1, 2, 3},
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}
	}};

	t_matrix C = {{
		{1, 2, 3, 4},
		{2, 4, 4, 2},
		{8, 6, 4, 1},
		{0, 0, 0, 1}
	}};

	t_matrix D = {{
		{18, 8, 23, 14},
		{28, 42, 4, 2},
		{18, 6, 4, 1},
		{0, 0, 0, 1}
	}};

	t_matrix E = {{
		{-5, 2, 6, -8},
		{1, -5, 1, 8},
		{7, 7, -6, -7},
		{1, -3, 7, 4}
	}};

	t_matrix F = {{
		{8, -5, 9, 2},
		{7, 5, 6, 1},
		{-6, 0, 9, 6},
		{-3, 0, -9, -4}
	}};*/

	/*t_matrix G = {{
		{9, 3, 0, 9},
		{0, -2, 0, 0},
		{0, 0, 6, 0},
		{0, 0, 0, 2}
	}};
	//t_column b = {{1, 2, 3, 1}};

	 t_matrix result = matrix_mult(A, B);
	t_column c = matrix_mult_col(C, b);
	printf("Result matrix:\n");
	print_matrix(result, 4);
	printf("Result column:\n");
	print_column(c);
	printf("Result transpose:\n");
	//C = transpose(A);
	print_matrix(transpose(C), 4);
	printf("Matrix D:\n");
	print_matrix(D, 4);
	printf("Matrix E:\n");
	print_matrix(E, 4);
	printf("A is invertible: %d\n", is_invertible(A));
	printf("D is invertible: %d\n", is_invertible(D));
	printf("Inverse of E:\n");
	print_matrix(inverse(E, 4), 4);
	printf("Inverse of F:\n");
	print_matrix(inverse(F, 4), 4);
	printf("Inverse of G:\n");
	print_matrix(inverse(G, 4), 4);
	printf("Multiplication by inverse:\n");
	print_matrix(matrix_mult(inverse(G, 4), G), 4);
	t_tup a = vector(2, 3, 4);
	printf("Vector a:\n");
	print_tuple(a);
	printf("Vector a after translation:\n");
	print_tuple(translate(a, 5, 3, 5));
	t_tup e = point(2, 3, 4);
	printf("Vector e:\n");
	print_tuple(e);
	printf("Point e after translation:\n");
	print_tuple(translate(e, 5, 3, 5));
	printf("Vector a after scaling:\n");
	print_tuple(scale(a, 5, 3, 5));
	printf("Point e after scaling:\n");
	print_tuple(scale(e, 2, 3, 4));
	printf("Vector after reversing scaling:\n");
	print_tuple(inverse_scale(vector(-4, 6, 8), 2, 3, 4));
	t_tup f = vector(2, 3, 4);
	printf("Vector f:\n");
	print_tuple(f);
	printf("Vector f after reflection:\n");
	print_tuple(scale(e, -1, 1, 1));
	printf("Triangular matrix: %d\n", is_triangular(G, 4));
	clock_t start_time = clock();
	determinant(F, 4);
	clock_t end_time = clock();
	double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Elapsed time: %lf seconds\n", elapsed_time);
	printf("Non-triangular matrix: %d\n", is_triangular(F, 4));*/

 	/* t_ray	ray;

	ray = ray_new(point(1, 2, 3), vector(0, 1, 0));
	print_tuple(position(ray, 0));
	print_tuple(position(ray, 1));
	print_tuple(position(ray, -1));
	print_tuple(position(ray, 2.5));

	t_obj *sphere = (t_obj *)sphere_create(2);
	sphere->transform(sphere, scaling_matrix(2,2,2));
	printf("Determinant transformation: %f\n",determinant(sphere->transformation, 4));
	t_inter i = intersect_sphere(ray_new(point(0, 0, -5), vector(0, 0, 1)), sphere);
	if (i.count)
		printf("Intersect count: %d\nIntersect 1: %f\nIntersect 2: %f\n",
			i.count, i.i[0].t, i.i[1].t);
	else
		printf("No intersect");*/
	// i = intersect_sphere(ray_new(point(0, 0, -5), vector(0, 0, 1)), sphere);
	// printf("Intersect count: %d\nIntersect 1: %f\nIntersect 2: %f\n",
	// 	i.count, i.i[0].t, i.i[1].t);
	/* i = intersect_sphere(ray_new(point(0, 1, -5), vector(0, 0, 1)), sphere);
	printf("Intersect count: %d\nIntersect 1: %f\nIntersect 2: %f\n",
		i.count, i.i[0].t, i.i[1].t);
	i = intersect_sphere(ray_new(point(0, 0, 0), vector(0, 0, 1)), sphere);
	printf("Intersect count: %d\nIntersect 1: %f\nIntersect 2: %f\n",
		i.count, i.i[0].t, i.i[1].t);
	t_inter inters = intersections(4, intersection(-1, sphere), intersection(1, sphere),
			intersection(-3, sphere), intersection(-2, sphere));
	t_intersection h = hit(inters);
	printf("Hit t: %f\n", h.t);
	print_matrix(sphere->transform, 4);*/

	/* t_ray r1 = ray_transform(ray, translation_matrix(3, 4, 5));
	t_ray r2 = ray_transform(ray, scaling_matrix(2, 3, 4));
	printf("Ray after translation\n");
	print_ray(r1);
	printf("Ray after scaling\n");
	print_ray(r2); */


// 	return 0;
// }

void	test_gameloop(t_main *rt)
{
	t_world		w;
	t_view_cam	cam;
	t_tup		from;
	t_tup		to;
	t_tup		up;
	t_obj		*floor;
	t_obj		*left_wall;
	t_obj		*right_wall;
	t_obj		*middle;
	t_obj		*right;
	t_obj		*left;

	init_mlx(&rt->mlx);
	w = create_world();
	floor = w.shapes;
	floor->transform(floor, scaling_matrix(10, 0.01, 10));
	floor->material = mat_default();
	floor->material.diffuse = 0.9;
	floor->material.specular = 0;
	floor->material.color = color(255, 230, 230);
	left_wall = w.shapes->next;
	left_wall->transform(left_wall, matrix_mult(translation_matrix(0, 0, 5),
												matrix_mult(rotation_y(-45),
												matrix_mult(rotation_x(90),
												scaling_matrix(100, 0.01, 100)))));
	left_wall->material = floor->material;
	right_wall = w.shapes->next->next;
	right_wall->transform(right_wall, matrix_mult(translation_matrix(0, 0, 5),
												matrix_mult(rotation_y(45),
												matrix_mult(rotation_x(90),
												scaling_matrix(100, 0.01, 100)))));
	right_wall->material = floor->material;
	middle = w.shapes->next->next->next;
	middle->transform(middle, translation_matrix(-0.5, 1, 0.5));
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	middle->material.color = color(25.5, 255, 127.5);
	right = w.shapes->next->next->next->next;
	right->transform(right, translation_matrix(1.5, 0.5, -0.5));
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;
	right->material.color = color(127.5, 255, 25.5);
	left = w.shapes->next->next->next->next->next;
	left->transform(left, translation_matrix(-1.5, 0.33, -0.75));
	left->material.diffuse = 0.7;
	left->material.specular = 0.3;
	left->material.color = color(255, 204, 25.5);
	cam = init_camera(1000, 1000, PI/3);
	from = point(0, 1.5, -5);
	to = point(0, 1, 0);
	up = vector(0, 1, 0);
	cam.transf_matrix = view_transform(from, to, up);
	render(cam, w, rt);
	handle_events(rt);
	mlx_loop(rt->mlx.mlx_ptr);
}

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
	print_scene_details();
	//test_gameloop(rt);

	// RUNS THE RENDER TEST WITH GIVEN .RT FILE CHECK test_scene_render(rt, av[1])
	if (!debug)
	{
		test_scene_render(rt, av[1]);
		return (0);
	}
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
	free(xs.i);

	t_obj *ob = get_scene()->obj_list;
	t_ray ra = ray_new(point(0, -1, 0), vector(0, 1, 0));
	t_inter in = ob->local_intersect(ra, ob);
	printf("Count: %d\nT_0: %f\n", in.count, in.i[0].t);
	free(in.i);
	//game_loop(rt);
	lighting_test_battery();
	ray_test_battery();
	hit_test_battery();


	/* t_matrix A = translation_matrix(0, 1, 0);
	t_obj *ob = get_scene()->obj_list;
	ob->transform(ob, A);
	t_tup a = normal_at(ob, point(0, 1.70711, -0.70711));
	print_tuple(a); */
	free(rt);

	// game_loop(rt);

	/* t_tup eyev = vector(0, 0, -1);
	t_tup normalv = vector(0, 0, -1);
	t_obj *sphere = get_scene()->obj_list;
	t_tup p = point(0, 0, 0);
	t_color l = lighting(sphere->material, p, eyev, normalv);
	print_color(l); */
	//draw_circle(rt);
	//print_tuple(vector_reflect(vector(0, -1, 0), vector(sqrt(2)/2, sqrt(2)/2, 0)));
}

