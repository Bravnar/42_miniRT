#include "main.h"

void	game_loop(t_main *rt)
{
	//init_mlx(&rt->mlx);
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

/*PARSING TESTING MAIN */

int main(void)
{
	t_main  *rt;

	rt = init_all("test_rt/minimalist.rt");
	if (!rt)
		exit(1);
	populate_scene_struct("test_rt/minimalist.rt", get_scene());
	print_scene_details();
	//draw_projectile(rt);
	free(rt);
}
