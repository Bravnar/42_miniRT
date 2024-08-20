#include "main.h"

// STAN TESTER MAIN
int	main(int ac, char **av)
{
	t_main 	*rt;

	if (ac < 2)
		err_handler(NO_ARGS);
	if (ac == 2)
	{
		rt = init_all(av[1]);
		if (!rt)
			exit(1);
		populate_scene_struct(av[1], get_scene());
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
	return (0);
}

