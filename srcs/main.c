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

	t_column b = {{1, 2, 3, 1}};

	t_matrix result = matrice_mult(A, B);
	t_column c = matrice_mult_col(C, b);
	printf("Result matrix:\n");
	print_matrix(result);
	printf("Result column:\n");
	print_column(c);
	printf("Result transpose:\n");
	C = transpose(A);
	print_matrix(transpose(C));
	return 0;
}
