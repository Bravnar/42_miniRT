#include "main.h"

t_matrix	rotation_z_pat(double angle)
{
	return (matrix_mult(rotation_z(angle), rotation_y(-angle/2)));
}
