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
}

double	volume_cy(t_obj *shape)
{
	t_cyl		*cyl;
	double		radius;

	cyl = (t_cyl *)shape;
	radius = cyl->diameter / 2.0;
	return ((PI * pow(radius, 2)) * cyl->height);
}

t_cyl	*cyl_create(char **cyl_line)
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
	pat = pattern(get_color(cyl_line[5]), white(), PLAIN);
	cyl->shape.material = material(pat, 0.9, 0.9, 200);
	cyl->shape.point = get_point(cyl_line[1]);
	cyl->shape.dir_vector = get_vector(cyl_line[2]);
	cyl->shape.next = NULL;
	cyl->shape.transformation = identity();
	cyl->shape.inverse_transformation = identity();
	cyl->shape.transform((t_obj *) cyl,
			matrix_mult(translation_matrix(cyl->shape.point.x,
				cyl->shape.point.y,
				cyl->shape.point.z),
			scaling_matrix(cyl->diameter / 2,
				cyl->diameter / 2,
				cyl->diameter / 2)));
	return (cyl);
}

void	cyl_destroy(t_obj *shape)
{
	t_cyl	*cyl;

	cyl = (t_cyl *)shape;
	free(cyl);
}
