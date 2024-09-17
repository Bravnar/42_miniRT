#include "main.h"

t_tup	str_to_vector(char *str)
{
	char	**str_split;
	t_tup	ret;
	bool	check_x;
	bool	check_y;
	bool	check_z;

	str_split = ft_split(str, ',');
	ret = vector(range_double(str_split[0], -1.0, 1.0),
			range_double(str_split[1], -1.0, 1.0),
			range_double(str_split[2], -1.0, 1.0));
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
	r = range_double(color_split[0], 0.0, 255.0);
	g = range_double(color_split[1], 0.0, 255.0);
	b = range_double(color_split[2], 0.0, 255.0);
	ret = color(r, g, b);
	ft_free_arr(color_split);
	return (ret);
}

double	range_double(char *line, double lower, double upper)
{
	double	number;

	number = ft_strtod(line);
	if (number < lower || number > upper)
	{
		ft_fprintf(2, BOLD_RED"%s\n"RESET, ERRLINE);
		ft_fprintf(2, BOLD_RED"RangeError\n\n"RESET);
		ft_fprintf(2, "%s , is out of range\n", line);
		printf("lower limit: %.2f, upper limit: %.2f\n", lower, upper);
		err_template("Parameter out of specified range", line);
	}
	return (number);
}

int	range_int(char *line, int lower, int upper)
{
	int	number;

	number = ft_rt_atoi(line);
	if (number < lower || number > upper)
	{
		ft_fprintf(2, BOLD_RED"%s\n"RESET, ERRLINE);
		ft_fprintf(2, BOLD_RED"RangeError\n\n"RESET);
		ft_fprintf(2, "%s , is out of range\n", line);
		printf("lower limit: %d, upper limit: %d\n", lower, upper);
		err_template("Parameter out of specified range", line);
	}
	return (number);
}