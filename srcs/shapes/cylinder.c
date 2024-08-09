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
	t_cyl	*cyl;

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
	cyl->shape.material = material(get_color(cyl_line[5]), 0.9, 0.9, 200);
	cyl->shape.point = get_point(cyl_line[1]);//parse_point;
	cyl->shape.dir_vector = get_vector(cyl_line[2]);//parse_vector;
	cyl->shape.next = NULL;
	cyl->shape.transformation = identity();
	cyl->shape.inverse_transformation = identity();
	return (cyl);
}

void	cyl_destroy(t_obj *shape)
{
	t_cyl	*cyl;

	cyl = (t_cyl *)shape;
	free(cyl);
}
