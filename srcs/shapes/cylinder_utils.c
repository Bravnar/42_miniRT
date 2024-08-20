#include "main.h"

void	transform_cy(t_obj *shape, t_matrix transformation)
{
	t_cyl	*cyl;

	cyl = (t_cyl *) shape;
	cyl->shape.transformation = matrix_mult(cyl->shape.transformation,
			transformation);
	cyl->shape.transformation = matrix_mult(cyl->shape.inverse_transformation,
			inverse(transformation, 4));
}

t_inter	null_intersect(void)
{
	t_inter	ret;

	ret.count = 0;
	ret.i = NULL;
	return (ret);
}
t_inter	local_intersect_cy(t_ray r, t_obj *cyl)
{
	double	a;
	double	b;
	double	c;
	t_inter	ret;
	
	ret = null_intersect();
	a = pow(r.direction.x, 2) + pow(r.direction.z, 2);
	printf("a = %.2f\n", a);
	if (equal(a, 0))
		return (ret);
	b = 2 * r.point.x * r.direction.x + 2 * r.point.z * r.direction.z;
	c = pow(r.point.x, 2) + pow(r.point.z, 2) - 1;
	double	disc = pow(b, 2) - 4 * a * c;
	if (disc < 0)
		return (ret);
	ret.i = malloc(sizeof(t_intersection) * 2);
	if (!ret.i)
		return (ret);
	double t0 = (-b - sqrt(disc)) / (2 * a);
	double t1 = (-b + sqrt(disc)) / (2 * a);
	double	cyl_min = 1;
	double	cyl_max = 2;
	double y0 = r.point.y + t0 * r.direction.y;
	if (cyl_min < y0 && y0 < cyl_max)
	{
		ret.count++;
		ret.i[0] = intersection(t0, cyl);
	}
	double y1 = r.point.y + t1 * r.direction.y;
	if (cyl_min < y1 && y1 < cyl_max)
	{
		ret.count++;
		ret.i[1] = intersection(t1, cyl);
	}
	// ret.i[0] = intersection((-b - sqrt(disc)) / (2 * a), cyl);
	// ret.i[1] = intersection((-b + sqrt(disc)) / (2 * a), cyl);
	return (ret);
}

t_cyl	*cylinder(void)
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
	return (cyl);
}
