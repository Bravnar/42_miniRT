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
	//draw_rectangle(rt);
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
	normal = normal_at(hit.shape, point);
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
	// sphere = (t_obj *)sphere_create(2);
	// sphere = search_obj_list("Sphere");
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
			//ray = ray_new(get_scene_cam()->point, get_scene_cam()->vector);
			inter = sphere->local_intersect(ray, sphere);
			if (inter.i)
			{
				t_intersection hit_info = hit(inter);
				if (hit_info.t != -1)
				{
					my_pixel(&rt->mlx, x, y, color_at_hit(hit_info, ray).hex);
					free(inter.i);
				}
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

// STAN TESTER MAIN
int main(int ac, char **av)
{
	t_main  *rt;

	if (ac != 2)
		return (0);
	rt = init_all(av[1]);
	if (!rt)
		exit(1);
	populate_scene_struct(av[1], get_scene());
	/*print_scene_details();
	printf("Creating world -------------------------------------------:\n");
	t_world	w;
	w = create_world();
	t_ray	r = ray_new(point(0, 0, -5), vector(0, 0, 1));
	t_inter	xs = intersect_world(w, r);
	printf("xs: count = %d\n", xs.count);
	int	i = -1;
	while (++i < xs.count)
		printf("xs[%d].t = %f\n", i, xs.i[i].t);
	free(xs.i);


	game_loop(rt); */

	t_matrix A = translation_matrix(0, 1, 0);
	t_obj *ob = get_scene()->obj_list;
	ob->transform(ob, A);
	t_tup a = normal_at(ob, point(0, 1.70711, -0.70711));
	print_tuple(a);
	free(rt);
}

