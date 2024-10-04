/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetching_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:45:45 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/20 10:47:40 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_tup	str_to_vector(char *str)
{
	char	**str_split;
	t_tup	ret;

	str_split = ft_split(str, ',');
	if (ft_arr_len(str_split) != 3)
	{
		add_error(str, "A vector should contain 3 values");
		ft_free_arr(str_split);
		return (vector(0, 0, 0));
	}
	ret = vector(range_double(str_split[0], -1.0, 1.0),
			range_double(str_split[1], -1.0, 1.0),
			range_double(str_split[2], -1.0, 1.0));
	ft_free_arr(str_split);
	return (ret);
}

t_tup	str_to_point(char *str)
{
	char	**str_split;
	t_tup	ret;

	str_split = ft_split(str, ',');
	if (ft_arr_len(str_split) != 3)
	{
		add_error(str, "A point should contain 3 values");
		ft_free_arr(str_split);
		return (point(0, 0, 0));
	}
	ret = point(ft_strtod(str_split[0]),
			ft_strtod(str_split[1]),
			ft_strtod(str_split[2]));
	ft_free_arr(str_split);
	return (ret);
}

t_color	color_split(char *color_str)
{
	t_color	ret;
	char	**color_split;
	int		r;
	int		g;
	int		b;

	color_split = ft_split(color_str, ',');
	if (ft_arr_len(color_split) != 3)
	{
		add_error(color_str, "A color should contain 3 values");
		ft_free_arr(color_split);
		return (white());
	}
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
		add_error(line, "Out of Specified Range");
	}
	return (number);
}

int	range_int(char *line, int lower, int upper)
{
	int	number;

	number = ft_rt_atoi(line);
	if (number < lower || number > upper)
	{
		add_error(line, "Out of Specified Range");
	}
	return (number);
}
