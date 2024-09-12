#include "main.h"


/* PLEASE KEEP THIS TINY MAIN SOMEWHERE AS A COMMENT
   WHEN MERGING OBV KEEP THE ORIGINAL :) */

int	main(int ac, char **av)
{
	t_mrt	*mrt;

	#pragma
	if (ac != 2)
		return (1);
	mrt = initialize(av[1]);
	print_scene_details();
	free(mrt);
	return (0);
}
/* 
void	test_cy(void)
{
	t_obj	*cyl;

	t_world	w;
	w = create_world();
	cyl = w.shapes;
	t_tup direction = vector_norm(vector(0, 0, 1));
	t_ray r = ray_new(point(0, 1.5, -2), direction);
	t_inter	*xs = cyl->local_intersect(r, cyl);
	print_inter(&xs);
} */

// STAN TESTER MAIN
/* int	main(int ac, char **av)
{
	t_mrt	*mrt;

	if (ac < 2)
		err_handler(NO_ARGS);
	if (ac == 2)
	{
		mrt = initialize(av[1]);
		if (!mrt)
			exit(1);
		// populate_scene_struct(av[1], get_scene());
		// test_cy();
		// return (0);
		// print_color(get_scene()->light->intensity);
		//tests();
		test_scene_render(mrt, av[1]);
		free(mrt);
	}
  return (0);
} */
 



