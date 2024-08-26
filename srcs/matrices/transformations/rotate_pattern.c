#include "main.h"

t_matrix	rotation_z_pat(double angle, char *name)
{
	if (!ft_strcmp("sphere", name))
		return (matrix_mult(rotation_z(angle), rotation_y(-angle / 4 * 3 )));
	if (!ft_strcmp("plane", name))
		return (matrix_mult(rotation_z(angle), rotation_y(+angle / 3 * 2)));
	return (matrix_mult(rotation_z(angle), rotation_y(+angle / 3 * 2)));
}
