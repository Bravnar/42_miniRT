#include "main.h"

t_mrt	*initialize(char *filename)
{
	t_mrt	*mrt;

	mrt = ft_calloc(1, sizeof(t_mrt));
	if (!mrt)
		return (NULL);
	mrt->map = create_map(filename);
	init_mlx(&mrt->mlx);
	return mrt;
}