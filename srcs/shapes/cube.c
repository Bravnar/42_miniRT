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

static void	transform(t_obj *shape, t_matrix transformation)
{
	t_cube	*cube;

	cube = (t_cube *) shape;
	cube->shape.transformation = matrix_mult(cube->shape.transformation,
			transformation);
	cube->shape.transformation = matrix_mult(cube->shape.inverse_transformation,
			inverse(transformation, 4));
}

t_cube	*cube_create(char **cube_line)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	if (!cube)
		return (NULL);
	cube->length = ft_strtod(cube_line[3]);
	cube->width = ft_strtod(cube_line[4]);
	cube->height = ft_strtod(cube_line[5]);
	cube->shape.get_name = get_name;
	cube->shape.volume = volume;
	cube->shape.destroy = cube_destroy;
	cube->shape.transform = transform;
	cube->shape.point = get_point(cube_line[1]);//parse_point;
	cube->shape.dir_vector = get_vector(cube_line[2]);//parse_vector;
	cube->shape.color = get_color(cube_line[6]);//parse_rgb;
	cube->shape.transformation = identity();
	cube->shape.inverse_transformation = identity();
	cube->shape.next = NULL;
	return (cube);
}

void	cube_destroy(t_obj *shape)
{
	t_cube	*cube;

	cube = (t_cube *)shape;
	free(cube);
}
