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

t_matrix rotation_axis_angle(t_tup axis, double angle) {
    axis = vector_norm(axis);
    double x = axis.x;
    double y = axis.y;
    double z = axis.z;
    double cos_theta = cos(angle);
    double sin_theta = sin(angle);
    double one_minus_cos = 1 - cos_theta;

    t_matrix rotation = identity();

    rotation.m[0][0] = cos_theta + x * x * one_minus_cos;
    rotation.m[0][1] = x * y * one_minus_cos - z * sin_theta;
    rotation.m[0][2] = x * z * one_minus_cos + y * sin_theta;

    rotation.m[1][0] = y * x * one_minus_cos + z * sin_theta;
    rotation.m[1][1] = cos_theta + y * y * one_minus_cos;
    rotation.m[1][2] = y * z * one_minus_cos - x * sin_theta;

    rotation.m[2][0] = z * x * one_minus_cos - y * sin_theta;
    rotation.m[2][1] = z * y * one_minus_cos + x * sin_theta;
    rotation.m[2][2] = cos_theta + z * z * one_minus_cos;

    return rotation;
}

t_matrix apply_transformation_cy(t_cyl *cyl)
{
    t_matrix scaling = scaling_matrix(cyl->diameter / 2, cyl->height / 2, cyl->diameter / 2);
    t_matrix rotation;
    t_matrix translation = translation_matrix(cyl->shape.point.x, cyl->shape.point.y, cyl->shape.point.z);

    t_tup default_dir = vector(0, 1, 0); // Default up direction
    t_tup desired_dir = vector_norm(cyl->shape.dir_vector);

    // Check if the default direction and desired direction are the same or opposite
    if (equal_tuple(default_dir, desired_dir)) {
        rotation = identity();
    } else if (equal_tuple(default_dir, tuple_neg(desired_dir))) {
        // 180-degree rotation around any perpendicular axis
        rotation = rotation_x(PI); // Or rotation around any axis perpendicular to default_dir
    } else {
        t_tup rotation_axis = vector_cross(default_dir, desired_dir);
        double rotation_angle = acos(vector_dot(default_dir, desired_dir));
        rotation = rotation_axis_angle(rotation_axis, rotation_angle);
    }

    t_matrix transformation = matrix_mult(matrix_mult(translation, rotation), scaling);
    return transformation;
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
	double	inv_y;

	cyl = (t_cyl *) obj;
	inv_y = 1.0 / r.direction.y;
	if (!cyl->closed || equal(obj->dir_vector.y, 0))
		return ;
	t = (cyl->min - r.point.y) * inv_y;
	if (check_cap(r, t) && t > EPSILON)
	{
		add_inter_node(inter, new_inter_node(intersection(t, obj)));
	}
	t = (cyl->max - r.point.y) * inv_y;
	if (check_cap(r, t) && t > EPSILON)
	{
		add_inter_node(inter, new_inter_node(intersection(t, obj)));
	}
}
