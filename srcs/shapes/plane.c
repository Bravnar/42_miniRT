#include "main.h"

char	*get_name_pl(t_obj *shape)
{
	(void) shape;
	return ("Plane");
}

void	transform_pl(t_obj *shape, t_matrix transformation)
{
	t_plane	*plane;

	plane = (t_plane *) shape;
	plane->shape.transformation = matrix_mult(plane->shape.transformation,
			transformation);
	plane->shape.transformation = matrix_mult(
			plane->shape.inverse_transformation,
			inverse(transformation, 4));
}

t_plane	*plane_create(char **plane_line)
{
	t_plane		*p;
	t_pattern	pat;

	p = malloc(sizeof(t_plane));
	if (!p)
		return (NULL);
	p->shape.get_name = get_name_pl;
	p->shape.volume = 0;
	p->shape.destroy = plane_destroy;
	p->shape.local_normal_at = local_normal_at_pl;
	p->shape.transform = transform_pl;
	p->shape.local_intersect = local_intersect_pl;
	p->shape.point = get_point(plane_line[1]);
	p->shape.dir_vector = vector_norm(get_vector(plane_line[2]));
	pat = pattern(get_color(plane_line[2]), c("pink"), GRADIENT, rotation_z_pat(45, "plane"));
	p->shape.material = material(pat, 0.9, 0, 200);
	p->shape.transformation = identity();
	p->shape.inverse_transformation = identity();
	p->shape.transform((t_obj *) p, translation_matrix(
			p->shape.point.x, p->shape.point.y, p->shape.point.z));
	p->shape.next = NULL;
	return (p);
}

void	plane_destroy(t_obj *shape)
{
	t_plane	*plane;

	plane = (t_plane *)shape;
	free(plane);
}
