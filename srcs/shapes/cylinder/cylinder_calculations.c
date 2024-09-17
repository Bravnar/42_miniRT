#include "main.h"

t_tup	calculate_rotations(t_tup dir_vector)
{
	double	theta_x;
	double	theta_y;
	double	theta_z;

	theta_x = atan2(dir_vector.z, dir_vector.x) * (180 / PI);
	theta_y = atan2(dir_vector.y, dir_vector.z) * (180 / PI);
	theta_z = atan2(dir_vector.x, dir_vector.y) * (180 / PI);
	return (point(theta_x, theta_y, theta_z));
}

t_matrix	apply_transformation_cy(t_cyl *cyl)
{
	t_matrix	transformation;
	t_matrix	scaling;
	t_matrix	rotation;
	t_matrix	translation;
	t_tup		thetas;

	scaling = scaling_matrix(cyl->diameter / 2,
			cyl->diameter / 2,
			cyl->diameter / 2);
	thetas = calculate_rotations(cyl->shape.dir_vector);
	rotation = matrix_mult(rotation_x(thetas.x), rotation_y(thetas.y));
	rotation = matrix_mult(rotation, rotation_z(thetas.z));
	translation = translation_matrix(cyl->shape.point.x,
			cyl->shape.point.y,
			cyl->shape.point.z);
	transformation = matrix_mult(matrix_mult(translation, rotation), scaling);
	return (transformation);
}

double	discriminant_cyl(t_obj *cyl, double *a, double *b)
{
	double	c;
	double	disc;

	*a = pow(cyl->saved_ray.direction.x, 2) \
		+ pow(cyl->saved_ray.direction.z, 2);
	if (fabs(*a) < DBL_EPSILON)
		return (-1);
	*b = 2 * cyl->saved_ray.point.x * cyl->saved_ray.direction.x \
		+ 2 * cyl->saved_ray.point.z * cyl->saved_ray.direction.z;
	c = pow(cyl->saved_ray.point.x, 2) + pow(cyl->saved_ray.point.z, 2) - 1;
	disc = pow(*b, 2) - 4 * *a * c;
	return (disc);
}

bool	check_cap(t_ray r, double t)
{
	double	x;
	double	z;
	double	result;

	x = r.point.x + r.direction.x * t;
	z = r.point.z + r.direction.z * t;
	result = pow(x, 2) + pow(z, 2);
	return (result < 1 || equal(result, 1));
}

void	intersect_caps(t_obj *obj, t_ray r, t_inter **inter)
{
	t_cyl	*cyl;
	double	t;

	cyl = (t_cyl *) obj;
	if (!cyl->closed || equal(obj->dir_vector.y, 0))
		return ;
	t = (cyl->min - r.point.y) / r.direction.y;
	if (check_cap(r, t))
	{
		add_inter_node(inter, new_inter_node(intersection(t, obj)));
	}
	t = (cyl->max - r.point.y) / r.direction.y;
	if (check_cap(r, t))
	{
		add_inter_node(inter, new_inter_node(intersection(t, obj)));
	}
}
