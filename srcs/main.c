#include "main.h"

void	game_loop(t_main *rt)
{
	init_mlx(&rt->mlx);
	draw_rectangle(rt);
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
	init_mlx(&rt->mlx);
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

int main(void)
{
	/* t_main  *rt;

	rt = init_main();
	if (!rt)
		exit(1);
	draw_projectile(rt);
	free(rt); */

	t_matrix A = {{
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
	}};

	t_matrix G = {{
		{9, 3, 0, 9},
		{-5, -2, -6, -3},
		{-4, 9, 6, 4},
		{-7, 6, 6, 2}
	}};
	t_column b = {{1, 2, 3, 1}};

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
	t_tup a = vector(1, 2, 3);
	printf("Vector a:\n");
	print_tuple(a);
	printf("Vector a after transformation:\n");
	print_tuple(translate_point(a, 5, 3, 5));
	t_tup e = point(1, 2, 3);
	printf("Vector e:\n");
	print_tuple(e);
	printf("Vector e after transformation:\n");
	print_tuple(translate_point(e, 5, 3, 5));
	return 0;
}


