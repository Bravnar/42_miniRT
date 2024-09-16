#include "main.h"

int	main(int ac, char **av)
{
	t_mrt	*mrt;

	if (ac < 2)
		err_handler(NO_ARGS);
	if (ac == 2)
	{
		mrt = initialize(av[1]);
		if (!mrt)
		// clean everything that needs to be cleaned
			exit(1);
		test_scene_render(mrt, av[1]);
		free(mrt);
	}
	// clean everything that needs to be cleaned
	return (0);
}
 