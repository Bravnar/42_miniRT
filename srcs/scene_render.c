#include "main.h"

void	render(t_view_cam cam, t_world w, t_mrt *rt)
{
	int		y;
	int		x;
	t_ray	new;
	t_color	c;

	y = -1;
	while (++y < cam.vsize - 1)
	{
		x = -1;
		while (++x < cam.hsize - 1)
		{
			new = ray_for_pixel(cam, x, y);
			c = iterative_color_at(w, new, 3);
			add_hex_color(&c);
			my_pixel(&rt->mlx, x, y, c.hex);
		}
	}
	mlx_put_image_to_window(rt->mlx.mlx_ptr,
		rt->mlx.win_ptr, rt->mlx.img_ptr, 0, 0);
}

void	gameplay_loop(t_view_cam view, t_world w, t_mrt *mrt)
{
	render(view, w, mrt);
	handle_events(mrt);
	mlx_loop(mrt->mlx.mlx_ptr);
}

void	setup_loop(t_mrt *mrt)
{
	t_cam	*cam;
	t_world	w;

	w = create_world();
	cam = get_scene_cam();
	gameplay_loop(cam->view, w, mrt);
}
