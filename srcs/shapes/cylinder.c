#include "main.h"

/* ********************************* */
/* CYLINDER STRUCT CREATION         */
/* To be called during map reading   */
/* ********************************* */

static char	*get_name(t_obj *shape)
{
	(void) shape;
	return ("Cylinder");
}

static double	volume(t_obj *shape)
{
	t_cyl		*cyl;
	double		radius;

	cyl = (t_cyl *)shape;
	radius = cyl->diameter / 2.0;
	return ((PI * pow(radius, 2)) * cyl->height);
}

static void	transform(t_obj *shape, t_matrix transformation)
{

	t_cyl	*cyl;

	cyl = (t_cyl *) shape;
	cyl->shape.transformation = matrix_mult(cyl->shape.transformation,
												transformation);
	cyl->shape.transformation = matrix_mult(cyl->shape.inverse_transformation,
												inverse(transformation, 4));
}

t_cyl	*cyl_create(double diameter, double height)
{
	t_cyl	*cyl;

	cyl = malloc(sizeof(t_cyl));
	if (!cyl)
		return (NULL);
	cyl->diameter = diameter;
	cyl->shape.get_name = get_name;
	cyl->shape.volume = volume;
	cyl->shape.destroy = cyl_destroy;
	cyl->shape.transform = transform;
	cyl->shape.point = point(0, 0 , 0);//parse_point;
	cyl->shape.dir_vector = vector(0, 0 , 0);//parse_vector;
	cyl->shape.color = color(255, 0 , 0);//parse_rgb;
	cyl->shape.next = NULL;
	cyl->shape.transformation = identity();
	cyl->shape.inverse_transformation = identity();
	cyl->height = height;
	return (cyl);
}

void	cyl_destroy(t_obj *shape)
{
	t_cyl	*cyl;

	cyl = (t_cyl *)shape;
	free(cyl);
}
