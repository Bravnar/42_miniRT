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

t_inter	local_intersect_cy(t_ray r, t_obj *cyl)
{
	t_ray	inv_ray;

	inv_ray = ray_transform(r, cyl->inverse_transformation);
	cyl->saved_ray = inv_ray;
	return (intersect(cyl));
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
