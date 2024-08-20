#include "main.h"

/* ********************************* */
/* CUBE STRUCT CREATION              */
/* To be called during map reading   */
/* ********************************* */

char	*get_name_cu(t_obj *shape)
{
	(void) shape;
	return ("Cube");
}

double	volume_cu(t_obj *shape)
{
	t_cube	*cube;

	cube = (t_cube *)shape;
	return (cube->length * cube->width * cube->height);
}

t_cube	*cube_create(char **cube_line)
{
	t_cube		*c;
	t_pattern	pat;

	c = malloc(sizeof(t_cube));
	if (!c)
		return (NULL);
	c->length = ft_strtod(cube_line[3]);
	c->width = ft_strtod(cube_line[4]);
	c->height = ft_strtod(cube_line[5]);
	c->shape.get_name = get_name_cu;
	c->shape.volume = volume_cu;
	c->shape.destroy = cube_destroy;
	c->shape.transform = transform_cu;
	c->shape.local_intersect = local_intersect_cu;
	pat = pattern(get_color(cube_line[6]), white(), PLAIN, identity());
	c->shape.material = material(pat, 0.9, 0.9, 200);
	c->shape.point = get_point(cube_line[1]);
	c->shape.dir_vector = get_vector(cube_line[2]);
	c->shape.transformation = identity();
	c->shape.inverse_transformation = identity();
	c->shape.next = NULL;
	return (c);
}

void	cube_destroy(t_obj *shape)
{
	t_cube	*cube;

	cube = (t_cube *)shape;
	free(cube);
}
