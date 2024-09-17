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

void	pat_mat_pl(char **plane_split, t_plane *plane)
{
	t_pattern	pat;
	t_color		prim;
	t_color		sec;

	prim = color_split(plane_split[2]);
	if (!RT_BONUS)
	{
		pat = pat_default(prim);
		plane->shape.material = material(pat, 0.9, 0.9, 200);
		plane->shape.material.refractive_index = 0;
		plane->shape.material.reflective = 0;
		plane->shape.material.transparency = 0;
	}
	else
	{
		sec = color_split(plane_split[4]);
		pat = pattern(prim, sec, range_int(plane_split[3], 0, 3),
			matrix_mult(rotation_z(0), scaling_matrix(1, 1, 1)));
		plane->shape.material = material (pat, 0.9, 0.9, 200);
		plane->shape.material.refractive_index = range_double(plane_split[6], 0.0, 5.0);
		plane->shape.material.reflective = range_double(plane_split[5], 0.0, 1.0);
		plane->shape.material.transparency = range_double(plane_split[7], 0.0, 1.0);
	}
}

t_plane	*plane_create(char **plane_line, int i)
{
	t_plane		*p;

	p = malloc(sizeof(t_plane));
	if (!p)
		return (NULL);
	plane_set_up(p, i);
	pat_mat_pl(plane_line, p);
	p->shape.point = str_to_point(plane_line[0]);
	p->shape.dir_vector = vector_norm(str_to_vector(plane_line[1]));
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
