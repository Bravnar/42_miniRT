#include "main.h"

t_color	get_color(char *str)
{
	char	**rgb_split;
	t_color	rgb;

	rgb_split = ft_split(str, ',');
	rgb = color(ft_atoi(rgb_split[0]),
			ft_atoi(rgb_split[1]),
			ft_atoi(rgb_split[2]));
	ft_free_arr(rgb_split);
	return (rgb);
}

t_tup	get_point(char *str)
{
	char	**point_split;
	t_tup	n_point;

	point_split = ft_split(str, ',');
	n_point = point(ft_strtod(point_split[0]),
			ft_strtod(point_split[1]),
			ft_strtod(point_split[2]));
	ft_free_arr(point_split);
	return (n_point);
}

t_tup	get_vector(char *str)
{
	char	**vector_split;
	t_tup	n_vector;

	vector_split = ft_split(str, ',');
	n_vector = vector(ft_strtod(vector_split[0]),
			ft_strtod(vector_split[1]),
			ft_strtod(vector_split[2]));
	ft_free_arr(vector_split);
	return (n_vector);
}

void	populate_shapes(void)
{
	t_parse	*tmp;
	t_obj	*(*create_shape)(char **, int);
	int		i;

	i = 0;
	tmp = get_scene()->file.parse;
	while (tmp)
	{
		create_shape = NULL;
		if (!ft_strcmp(tmp->line_split[0], "sp"))
			create_shape = (t_obj *(*)(char **, int))sphere_create;
		else if (!ft_strcmp(tmp->line_split[0], "cy"))
			create_shape = (t_obj *(*)(char **, int)) cyl_create;
		else if (!ft_strcmp(tmp->line_split[0], "pl"))
			create_shape = (t_obj *(*)(char **, int)) plane_create;
		else if (!ft_strcmp(tmp->line_split[0], "cu"))
			create_shape = (t_obj *(*)(char **, int)) cube_create;
		if (create_shape)
			add_obj_node(&get_scene()->obj_list, create_shape(tmp->line_split, i++));
		tmp = tmp->next;
	}
}
