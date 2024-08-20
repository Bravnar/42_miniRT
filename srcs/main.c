#include "main.h"

void	test_cy(void)
{
	t_obj	*cyl;

	t_world	w;
	w = create_world();
	cyl = w.shapes;
	t_tup direction = vector_norm(vector(0, 0, 1));
	t_ray r = ray_new(point(0, 1.5, -2), direction);
	t_inter	xs = cyl->local_intersect(r, cyl);
	printf("xs.count = %d\n", xs.count);
	print_inter(xs);
}

// STAN TESTER MAIN
int main(int ac, char **av)
{
	t_main  *rt;

	if (ac < 2)
		err_handler(NO_ARGS);
	if (ac == 2)
	{
		rt = init_all(av[1]);
		if (!rt)
			exit(1);
		populate_scene_struct(av[1], get_scene());
		// test_cy();
		// return (0);
		print_color(get_scene()->light->intensity);
		test_scene_render(rt, av[1]);
		free(rt);
	}
	else
	{
		lighting_test_battery();
		ray_test_battery();
		hit_test_battery();
	}
	// free(rt);
	return (0);
}

