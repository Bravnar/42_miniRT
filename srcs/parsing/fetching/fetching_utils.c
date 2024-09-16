#include "main.h"

t_tup	str_to_vector(char *str)
{
	char	**str_split;
	t_tup	ret;
	bool	check_x;
	bool	check_y;
	bool	check_z;

	str_split = ft_split(str, ',');
	ret = vector(ft_strtod(str_split[0]),
			ft_strtod(str_split[1]),
			ft_strtod(str_split[2]));
	check_x = ret.x >= -1.0 && ret.x <= 1.0;
	check_y = ret.y >= -1.0 && ret.y <= 1.0;
	check_z = ret.z >= -1.0 && ret.z <= 1.0;
	ft_free_arr(str_split);
	if (!check_x || !check_y || !check_z)
		err_template("Vector out of range", str);
	return (ret);
}

t_tup	str_to_point(char *str)
{
	char	**str_split;
	t_tup	ret;

	str_split = ft_split(str, ',');
	ret = point(ft_strtod(str_split[0]),
			ft_strtod(str_split[1]),
			ft_strtod(str_split[2]));
	ft_free_arr(str_split);
	return (ret);
}

t_color	color_split(char *color_str)
{
	t_color	ret;
	char **color_split;
	int	r;
	int	g;
	int	b;

	color_split = ft_split(color_str, ',');
	r = ft_strtod(color_split[0]);
	g = ft_strtod(color_split[1]);
	b = ft_strtod(color_split[2]);
	ret = color(r, g, b);
	ft_free_arr(color_split);
	return (ret);
}
