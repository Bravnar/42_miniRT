#include "main.h"

t_proj	proj_new(t_tup position, t_tup velocity)
{
	t_proj	new;

	new.position = position;
	if (!equal(vector_mag(velocity), 1.0))
		new.velocity = vector_norm(velocity);
	else
		new.velocity = velocity;
	return (new);
}
