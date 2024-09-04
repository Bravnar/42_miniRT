#include "main.h"

void	transform_cy(t_obj *shape, t_matrix transformation)
{
	t_cyl	*cyl;

	cyl = (t_cyl *) shape;
	cyl->shape.transformation = matrix_mult(cyl->shape.transformation,
			transformation);
	cyl->shape.inverse_transformation = matrix_mult(
			cyl->shape.inverse_transformation,
			inverse(transformation, 4));
}

double	discriminant_cyl(t_obj *cyl, double *a, double *b)
{
	double	c;
	double	disc;

	*a = pow(cyl->saved_ray.direction.x, 2) \
		+ pow(cyl->saved_ray.direction.z, 2);
	if (equal(*a, 0))
		return (-1);
	*b = 2 * cyl->saved_ray.point.x * cyl->saved_ray.direction.x \
		+ 2 * cyl->saved_ray.point.z * cyl->saved_ray.direction.z;
	c = pow(cyl->saved_ray.point.x, 2) + pow(cyl->saved_ray.point.z, 2) - 1;

	disc = pow(*b, 2) - 4 * *a * c;
	return (disc);
}

t_inter	*local_intersect_cy(t_ray r, t_obj *cyl)
{
	double	ab[2];
	double	disc;
	double	t;
	double	y;
	t_inter	*ret;

	cyl->saved_ray = ray_transform(r, cyl->inverse_transformation);
	ret = NULL;
	disc = discriminant_cyl(cyl, &ab[0], &ab[1]);
	if (disc < 0)
		return (ret);
	t = (-ab[1] - sqrt(disc)) / (2 * ab[0]);
	y = cyl->saved_ray.point.y + t * cyl->saved_ray.direction.y;
	if ((-((t_cyl *)cyl)->height / 2) < y \
		&& y < (((t_cyl *)cyl)->height) / 2)
		add_inter_node(&ret, new_inter_node(intersection(t, cyl)));
	t = (-ab[1] + sqrt(disc)) / (2 * ab[0]);
	y = cyl->saved_ray.point.y + t * cyl->saved_ray.direction.y;
	if ((-((t_cyl *)cyl)->height / 2 < y \
		&& y < (((t_cyl *)cyl)->height) / 2))
		add_inter_node(&ret, new_inter_node(intersection(t, cyl)));
	return (ret);
}

t_cyl	*cylinder(int i)
{
	t_cyl	*cyl;

	cyl = malloc(sizeof(t_cyl));
	if (!cyl)
		return (NULL);
	cyl->diameter = 2;
	cyl->height = 1;
	cyl->shape.get_name = get_name_cy;
	cyl->shape.volume = volume_cy;
	cyl->shape.destroy = cyl_destroy;
	cyl->shape.transform = transform_cy;
	cyl->shape.local_intersect = local_intersect_cy;
	cyl->shape.material = mat_default();
	cyl->shape.point = point(0, 0, 0);
	cyl->shape.dir_vector = vector(0, 0, 1);
	cyl->shape.next = NULL;
	cyl->shape.transformation = identity();
	cyl->shape.inverse_transformation = identity();
	cyl->shape.id = i;
	return (cyl);
}
