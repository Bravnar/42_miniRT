#include "main.h"

/* PLEASE KEEP THIS TINY MAIN SOMEWHERE AS A COMMENT
   WHEN MERGING OBV KEEP THE ORIGINAL :) */

int	main(int ac, char **av)
{
	t_mrt	*mrt;

	if (ac != 2)
		return (1);
	mrt = initialize(av[1]);
	print_scene_details();
	free(mrt);
	return (0);
}
