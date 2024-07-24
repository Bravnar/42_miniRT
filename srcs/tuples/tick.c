#include "main.h"

t_proj	tick(t_env env, t_proj proj)
{
	t_proj	new;

	new.position = tuple_add(proj.position, proj.velocity);
	new.velocity = tuple_add(proj.velocity, tuple_add(env.gravity, env.wind));
	return (new);
}
