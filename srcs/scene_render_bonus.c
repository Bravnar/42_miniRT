#include "main.h"
#include <pthread.h>

typedef struct s_render_data
{
	t_view_cam	cam;
	t_world		w;
	t_mrt		*mrt;
	int			start_y;
	int			end_y;
}	t_render_data;

void	*render_section(void *arg)
{
	t_render_data	*data;
	t_ray			new;
	t_color			c;
	int	x;
	int	y;

	data = (t_render_data *)arg;
	y = data->start_y;
	while (y < data->end_y)
	{
		x = 0;
		while (x < data->cam.hsize)
		{
			new = ray_for_pixel(data->cam, x, y);
			pthread_mutex_lock(&data->mrt->mlx_mutex);
			c = iterative_color_at(data->w, new, 3);
			add_hex_color(&c);
			my_pixel(&data->mrt->mlx, x, y, c.hex);
			pthread_mutex_unlock(&data->mrt->mlx_mutex);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	render_bonus(t_view_cam cam, t_world w, t_mrt *rt)
{
	pthread_t		threads[12];
	t_render_data	data[12];
	int				i;
	int				segment_height;

	segment_height = cam.vsize / 12;
	i = -1;
	while (++i < 12)
	{
		data[i].cam = cam;
		data[i].w = w;
		data[i].mrt = rt;
		data[i].start_y = i * segment_height;
		if (i == 11)
			data[i].end_y = cam.vsize;
		else
			data[i].end_y = (i + 1) * segment_height;
		pthread_create(&threads[i], NULL, render_section, (void *)&data[i]);
	}
	i = -1;
	while (++i < 12)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win_ptr, rt->mlx.img_ptr, 0, 0);
}

void	gameplay_loop_bonus(t_view_cam view, t_world w, t_mrt *mrt)
{
	render_bonus(view, w, mrt);
	handle_events(mrt);
	mlx_loop(mrt->mlx.mlx_ptr);
}

void	setup_loop_bonus(t_mrt *mrt)
{
	t_cam	*cam;
	t_world	w;

	w = create_world();
	cam = get_scene_cam();
	pthread_mutex_init(&mrt->mlx_mutex, NULL);
	gameplay_loop_bonus(cam->view, w, mrt);
	pthread_mutex_destroy(&mrt->mlx_mutex);
}
