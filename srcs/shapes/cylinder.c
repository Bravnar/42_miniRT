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
	double		dist;
	t_cyl		*cyll;
	t_tup		normal;

	cyll = (t_cyl *) cyl;
	dist = pow(point.x, 2) + pow(point.z, 2);
	if (dist < 1 && point.y >= cyll->max - EPSILON)
		normal = vector(0, 1, 0);
	else if (dist < 1 && point.y <= cyll->min + EPSILON)
		normal = vector(0, -1, 0);
	else
		normal = vector_norm(vector(point.x, 0, point.z));
	if (cyl->material.pattern.noise)
		normal = perturb_normal(cyl, point, normal, cyl->material.pattern);
	return (normal);
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
	t_matrix	cyl_transform;

	cyl = malloc(sizeof(t_cyl));
	if (!cyl)
		return (NULL);
	cyl->diameter = ft_strtod(cyl_line[2]);
	cyl->height = ft_strtod(cyl_line[3]);
	cyl->max = cyl->height / 2;
	cyl->min = -cyl->height / 2;
	cyl->shape.get_name = get_name_cy;
	cyl->shape.volume = volume_cy;
	cyl->shape.destroy = cyl_destroy;
	cyl->shape.transform = transform_cy;
	cyl->shape.local_intersect = local_intersect_cy;
	cyl->shape.local_normal_at = local_normal_at_cy;
	cyl->shape.point = str_to_point(cyl_line[0]);
	cyl->shape.dir_vector = str_to_vector(cyl_line[1]);
	cyl->shape.next = NULL;
	cyl_transform = apply_transformation_cy(cyl);
	pat = pattern(c("blue"), color_split(cyl_line[4]), PLAIN,
					  cyl_transform);
	cyl->shape.material = material(pat, 0.9, 0.9, 200);
	cyl->shape.material.reflective = 0;
	cyl->shape.transformation = identity();
	cyl->shape.inverse_transformation = identity();
	cyl->shape.transform((t_obj *) cyl, cyl_transform);
	cyl->shape.id = i;
	cyl->closed = true;
	return (cyl);
}

void	cyl_destroy(t_obj *shape)
{
	t_cyl	*cyl;

	cyl = (t_cyl *)shape;
	free(cyl);
}
