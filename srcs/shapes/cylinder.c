#include "main.h"

/* ********************************* */
/* CYLINDER STRUCT CREATION         */
/* To be called during map reading   */
/* ********************************* */

char	*get_name_cy(t_obj *shape)
{
	(void) shape;
	return ("Cylinder");
}

t_tup	local_normal_at_cy(t_obj *cyl, t_tup point)
{
	(void) cyl;
	return (vector(point.x, 0, point.z));
	// t_tup	center_to_point;
	// double	proj_length;
	// t_tup	projection;
	// t_tup	closest_point;
	// t_tup	normal;

	// center_to_point = tuple_sub(point, cyl->point);
	// proj_length = vector_dot(center_to_point, cyl->dir_vector);
	// projection = vector_scalar_mult(cyl->dir_vector, proj_length);
	// closest_point = tuple_add(cyl->point, projection);
	// normal = tuple_sub(point, closest_point);

	// return vector_norm(normal);
}

double	volume_cy(t_obj *shape)
{
	t_cyl		*cyl;
	double		radius;

	cyl = (t_cyl *)shape;
	radius = cyl->diameter / 2.0;
	return ((PI * pow(radius, 2)) * cyl->height);
}


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

t_cyl	*cyl_create(char **cyl_line, int i)
{
	t_cyl		*cyl;
	t_pattern	pat;

	cyl = malloc(sizeof(t_cyl));
	if (!cyl)
		return (NULL);
	cyl->diameter = ft_strtod(cyl_line[3]);
	cyl->height = ft_strtod(cyl_line[4]);
	cyl->shape.get_name = get_name_cy;
	cyl->shape.volume = volume_cy;
	cyl->shape.destroy = cyl_destroy;
	cyl->shape.transform = transform_cy;
	cyl->shape.local_intersect = local_intersect_cy;
	cyl->shape.local_normal_at = local_normal_at_cy;
	pat = pattern(get_color(cyl_line[5]), white(), PLAIN, identity());
	cyl->shape.material = material(pat, 0.9, 0.9, 200);
	cyl->shape.point = get_point(cyl_line[1]);
	cyl->shape.dir_vector = get_vector(cyl_line[2]);
	cyl->shape.next = NULL;
	cyl->shape.transformation = identity();
	cyl->shape.inverse_transformation = identity();
	// cyl->shape.transform((t_obj *) cyl,
	// 		matrix_mult(translation_matrix(cyl->shape.point.x,
	// 			cyl->shape.point.y,
	// 			cyl->shape.point.z),
	// 		scaling_matrix(cyl->diameter / 2,
	// 			cyl->diameter / 2,
	// 			cyl->diameter / 2)));
	cyl->shape.transform((t_obj *) cyl, apply_transformation_cy(cyl));
	cyl->shape.id = i;
	return (cyl);
}

void	cyl_destroy(t_obj *shape)
{
	t_cyl	*cyl;

	cyl = (t_cyl *)shape;
	free(cyl);
}
