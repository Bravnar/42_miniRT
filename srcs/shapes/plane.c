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

void	plane_set_up(t_plane *plane, int i)
{
	plane->shape.transformation = identity();
	plane->shape.inverse_transformation = identity();
	plane->shape.get_name = get_name_pl;
	plane->shape.volume = 0;
	plane->shape.destroy = plane_destroy;
	plane->shape.local_normal_at = local_normal_at_pl;
	plane->shape.transform = transform_pl;
	plane->shape.local_intersect = local_intersect_pl;
	plane->shape.next = NULL;
	plane->shape.id = i;
}

t_plane	*plane_create(char **plane_line, int i)
{
	t_plane		*p;
	t_pattern	pat;

	p = malloc(sizeof(t_plane));
	if (!p)
		return (NULL);
	plane_set_up(p, i);
	pat = pattern(c("purple"), c("pink"), STRIPE, rotation_z_pat(45, "plane"));
	p->shape.material = material(pat, 0.9, 0, 200);
	p->shape.point = str_to_point(plane_line[0]);
	p->shape.dir_vector = vector_norm(str_to_vector(plane_line[1]));
	p->shape.material.reflective = 0;
	p->shape.transform((t_obj *) p, translation_matrix(
			p->shape.point.x, p->shape.point.y, p->shape.point.z));
	return (p);
}

void	plane_destroy(t_obj *shape)
{
	t_plane	*plane;

	plane = (t_plane *)shape;
	free(plane);
}
