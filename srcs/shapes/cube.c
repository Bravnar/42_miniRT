#include "main.h"

/* ********************************* */
/* CUBE STRUCT CREATION              */
/* To be called during map reading   */
/* ********************************* */

static char	*get_name(t_obj *shape)
{
	(void) shape;
	return ("Cube");
}

static double	volume(t_obj *shape)
{
	t_cube	*cube;

	cube = (t_cube *)shape;
	return (cube->length * cube->width * cube->height);
}

t_cube	*cube_create(double length, double width, double height)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	if (!cube)
		return (NULL);
	cube->length = length;
	cube->width = width;
	cube->height = height;
	cube->shape.get_name = get_name;
	cube->shape.volume = volume;
	cube->shape.destroy = cube_destroy;
	cube->shape.point = ---;//parse_point;
	cube->shape.dir_vector = ---;//parse_vector;
	cube->shape.rgb = ---;//parse_rgb;
	cube->shape.next = NULL;
	return (cube);
}

void	cube_destroy(t_obj *shape)
{
	t_cube	*cube;

	cube = (t_cube *)shape;
	free(cube);
}
