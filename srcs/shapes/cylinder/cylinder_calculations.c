/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_calculations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 17/09/2024 20:10:02 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 09:46:14 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* t_tup	calculate_rotations(t_tup dir_vector)
{
	double	theta_x;
	double	theta_y;
	double	theta_z;

	theta_x = atan2(dir_vector.z, dir_vector.x) * (180 / PI);
	theta_y = atan2(dir_vector.y, dir_vector.z) * (180 / PI);
	theta_z = atan2(dir_vector.x, dir_vector.y) * (180 / PI);
	return (point(theta_x, theta_y, theta_z));
} */

t_matrix	rotation_axis_angle(t_tup axis, double angle)
{
	double		cos_theta;
	double		sin_theta;
	double		one_minus_cos;
	t_matrix	rotation;

	axis = vector_norm(axis);
	cos_theta = cos(angle);
	sin_theta = sin(angle);
	one_minus_cos = 1 - cos_theta;
	rotation = identity();
	rotation.m[0][0] = cos_theta + axis.x * axis.x * one_minus_cos;
	rotation.m[0][1] = axis.x * axis.y * one_minus_cos - axis.z * sin_theta;
	rotation.m[0][2] = axis.x * axis.z * one_minus_cos + axis.y * sin_theta;
	rotation.m[1][0] = axis.y * axis.x * one_minus_cos + axis.z * sin_theta;
	rotation.m[1][1] = cos_theta + axis.y * axis.y * one_minus_cos;
	rotation.m[1][2] = axis.y * axis.z * one_minus_cos - axis.x * sin_theta;
	rotation.m[2][0] = axis.z * axis.x * one_minus_cos - axis.y * sin_theta;
	rotation.m[2][1] = axis.z * axis.y * one_minus_cos + axis.x * sin_theta;
	rotation.m[2][2] = cos_theta + axis.z * axis.z * one_minus_cos;
	return (rotation);
}

t_matrix	apply_transformation_cy(t_cyl *cyl)
{
	t_matrix	scaling;
	t_matrix	rotation;
	t_matrix	translation;
	t_tup		desired_dir;

	desired_dir = vector_norm(cyl->shape.dir_vector);
	scaling = scaling_matrix(cyl->diameter / 2,
			cyl->height / 2, cyl->diameter / 2);
	translation = translation_matrix(cyl->shape.point.x,
			cyl->shape.point.y, cyl->shape.point.z);
	if (equal_tuple(vector(0, 1, 0), desired_dir))
		rotation = identity();
	else if (equal_tuple(vector(0, 1, 0), tuple_neg(desired_dir)))
		rotation = rotation_x(PI);
	else
	{
		rotation = rotation_axis_angle(
				vector_cross(vector(0, 1, 0), desired_dir),
				acos(vector_dot(vector(0, 1, 0), desired_dir)));
	}
	return (matrix_mult(matrix_mult(translation, rotation), scaling));
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
