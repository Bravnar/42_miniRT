#include "main.h"

t_env	env_new(t_tup wind, t_tup gravity)
{
	t_env	new;

	new.wind = wind;
	new.gravity = gravity;
	return (new);
}
