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
			exit(1);
		setup_loop_bonus(mrt);
		free(mrt);
	}
	return (0);
}
 