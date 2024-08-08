#include "main.h"

static char	*get_name(t_obj *shape)
{
	(void) shape;
	return ("Plane");
}

static void	transform(t_obj *shape, t_matrix transformation)
{
	t_plane	*plane;

	plane = (t_plane *) shape;
	plane->shape.transformation = matrix_mult(plane->shape.transformation,
		transformation);
	plane->shape.transformation = matrix_mult(plane->shape.inverse_transformation,
			inverse(transformation, 4));
}

static t_inter	local_intersect(t_ray r, t_obj *plane)
{
	double	t;
	t_inter	inter;

	inter.count = 0;
	if (equal(r.direction.y, 0))
		return (inter);
	inter.i = malloc(sizeof(t_intersection) * 1);
	if (!inter.i)
		return (inter);
	t = -r.point.y/r.direction.y;
	inter.count++;
	inter.i[0] = intersection(t, plane);
	return (inter);
}

static t_tup	local_normal_at(t_obj *plane, t_tup point)
{
	(void) plane;
	(void) point;
	return vector(0, 1, 0);
}

t_plane	*plane_create(char **plane_line)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->shape.get_name = get_name;
	plane->shape.volume = 0;
	plane->shape.destroy = plane_destroy;
	plane->shape.local_normal_at = local_normal_at;
	plane->shape.transform = transform;
	plane->shape.local_intersect = local_intersect;
	plane->shape.point = get_point(plane_line[1]);//parse_point;
	plane->shape.dir_vector = get_vector(plane_line[2]);//parse_vector;
	plane->shape.material = material(get_color(plane_line[3]), 0.9, 0.9, 200);
	plane->shape.transformation = identity();
	plane->shape.inverse_transformation = identity();
	plane->shape.next = NULL;
	return (plane);
}

void	plane_destroy(t_obj *shape)
{
	t_plane	*plane;

	plane = (t_plane *)shape;
	free(plane);
}
