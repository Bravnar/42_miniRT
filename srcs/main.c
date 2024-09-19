#include "main.h"

int	main(int ac, char **av)
{
	t_mrt	*mrt;

	if (ac < 2)
		err_handler(NO_ARGS);
	if (ac == 2)
	{
		if (!check_file_name(av[1]))
			err_template(M_WRONG_EXT, av[1]);
		mrt = initialize(av[1]);
		if (!mrt)
			exit(1);
		setup_loop(mrt);
		exit(0);
	}
	return (0);
}
