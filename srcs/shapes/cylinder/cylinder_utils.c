#include "main.h"

void	pat_mat_cy(char **cyl_split, t_cyl *cyl)
{
	t_pattern	pat;
	t_color		prim;
	t_color		sec;

	prim = color_split(cyl_split[4]);
	if (!RT_BONUS)
	{
		pat = pat_default(prim);
		cyl->shape.material = material(pat, 0.9, 0.9, 200);
		cyl->shape.material.refractive_index = 0;
		cyl->shape.material.reflective = 0;
		cyl->shape.material.transparency = 0;
	}
	else
	{
		sec = color_split(cyl_split[6]);
		pat = pattern(prim, sec, range_int(cyl_split[3], 0, 3),
			matrix_mult(rotation_z(0), scaling_matrix(1, 1, 1)));
		cyl->shape.material = material(pat, 0.9, 0.9, 200);
		cyl->shape.material.refractive_index = range_double(cyl_split[8], 0.0, 5.0);
		cyl->shape.material.reflective = range_double(cyl_split[7], 0.0, 1.0);
		cyl->shape.material.transparency = range_double(cyl_split[9], 0.0, 1.0);
	}
}

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

t_inter	*local_intersect_cy(t_ray r, t_obj *cyl)
{
	double	ab[2];
	double	disc;
	double	t;
	double	y;
	t_inter	*ret;

	cyl->saved_ray = ray_new(r.point, vector_norm(r.direction));
	cyl->saved_ray = ray_transform(cyl->saved_ray, cyl->inverse_transformation);
	ret = NULL;
	disc = discriminant_cyl(cyl, &ab[0], &ab[1]);
	if (disc < 0)
		return (ret);
	t = (-ab[1] - sqrt(disc)) / (2 * ab[0]);
	y = cyl->saved_ray.point.y + t * cyl->saved_ray.direction.y;
	if (((t_cyl *)cyl)->min < y \
		&& y < ((t_cyl *)cyl)->max)
		add_inter_node(&ret, new_inter_node(intersection(t, cyl)));
	t = (-ab[1] + sqrt(disc)) / (2 * ab[0]);
	y = cyl->saved_ray.point.y + t * cyl->saved_ray.direction.y;
	if ((((t_cyl *)cyl)->min < y \
		&& y < ((t_cyl *)cyl)->max))
		add_inter_node(&ret, new_inter_node(intersection(t, cyl)));
	intersect_caps(cyl, cyl->saved_ray, &ret);
	return (ret);
}

t_cyl	*cylinder(int i)
{
	t_cyl	*cyl;

	cyl = malloc(sizeof(t_cyl));
	if (!cyl)
		return (NULL);
	cyl_set_up(cyl, i);
	cyl->diameter = 2;
	cyl->height = 1;
	cyl->shape.material = mat_default();
	cyl->shape.point = point(0, 0, 0);
	cyl->shape.dir_vector = vector(0, 0, 1);
	cyl->max = DBL_MAX;
	cyl->min = DBL_MIN;
	return (cyl);
}