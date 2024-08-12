#include "main.h"

void	create_floor(t_obj *floor)
{
	floor = *get_scene_objs();
	floor->transform(floor, scaling_matrix(10, 0.01, 10));
	floor->material = mat_default();
	floor->material.diffuse = 0.9;
	floor->material.specular = 0;
	floor->material.color = color(255, 230, 230);
}

void	create_l_wall(t_obj *l_wall)
{
	l_wall = *get_scene_objs();
	l_wall = l_wall->next;
	l_wall->transform(l_wall, matrix_mult(translation_matrix(0, 0, 5),
											matrix_mult(rotation_y(-45),
											matrix_mult(rotation_x(90),
											scaling_matrix(100, 0.01, 100)))));
	l_wall->material.diffuse = 0.9;
	l_wall->material.specular = 0;
	l_wall->material.color = color(255, 230, 230);

}

void	create_r_wall(t_obj *r_wall)
{
	r_wall = *get_scene_objs();
	r_wall = r_wall->next->next;
	r_wall->transform(r_wall, matrix_mult(translation_matrix(0, 0, 5),
											matrix_mult(rotation_y(45),
											matrix_mult(rotation_x(90),
											scaling_matrix(100, 0.01, 100)))));
	r_wall->material.diffuse = 0.9;
	r_wall->material.specular = 0;
	r_wall->material.color = color(255, 230, 230);

}

void	test_scene_render(t_main *rt)
{
	// t_obj	*floor = NULL;
	// t_obj	*l_wall = NULL;
	// t_obj	*r_wall = NULL;
	t_cam	*cam;
	t_world	w;

	w = create_world();
	cam = get_scene_cam();
	init_mlx(&rt->mlx);
	// create_floor(floor);
	// create_l_wall(l_wall);
	// create_r_wall(r_wall);
	cam->view.transf_matrix = view_transform(cam->point,
							cam->vector,
							point(0, 1, 0));
	render(cam->view, w, rt);
	handle_events(rt);
	mlx_loop(rt->mlx.mlx_ptr);
}