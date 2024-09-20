/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetching_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:55:29 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/19 20:47:02 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef struct s_voidobj
{
	t_obj	shape;
}	t_voidobj;

void	void_destroy(t_obj *shape)
{
	t_voidobj	*obj;

	obj = (t_voidobj *)shape;
	free(obj);
}

t_voidobj	*void_create()
{
	t_voidobj *dummy;

	dummy = malloc(sizeof(t_voidobj));
	if (!dummy)
		return (dummy);
	dummy->shape.id = 1337;
	dummy->shape.destroy = void_destroy;
	dummy->shape.next = NULL;
	return (dummy);
}


t_tup	str_to_vector(char *str, void *tmp)
{
	char	**str_split;
	t_tup	ret;

	if (tmp != NULL)
	{
		(void) tmp;
		add_obj_node(&get_map()->obj_list, (t_obj *) void_create());
	}
	str_split = ft_split(str, ',');
	ret = vector(range_double(str_split[0], -1.0, 1.0, str_split),
			range_double(str_split[1], -1.0, 1.0, str_split),
			range_double(str_split[2], -1.0, 1.0, str_split));
	ft_free_arr(str_split);
	return (ret);
}

t_tup	str_to_point(char *str, void *tmp)
{
	char	**str_split;
	t_tup	ret;

	if (tmp != NULL)
	{
		(void) tmp;
		add_obj_node(&get_map()->obj_list, (t_obj *) void_create());
	}
	str_split = ft_split(str, ',');
	ret = point(ft_strtod(str_split[0], str_split),
			ft_strtod(str_split[1], str_split),
			ft_strtod(str_split[2], str_split));
	ft_free_arr(str_split);
	return (ret);
}

t_color	color_split(char *color_str, void *obj)
{
	t_color	ret;
	char	**color_split;
	int		r;
	int		g;
	int		b;

	if (obj != NULL)
	{
		(void) obj;
		add_obj_node(&get_map()->obj_list, (t_obj *) void_create());
	}
	color_split = ft_split(color_str, ',');
	r = range_double(color_split[0], 0.0, 255.0, color_split);
	g = range_double(color_split[1], 0.0, 255.0, color_split);
	b = range_double(color_split[2], 0.0, 255.0, color_split);
	ret = color(r, g, b);
	ft_free_arr(color_split);
	return (ret);
}

double	range_double(char *line, double lower, double upper, char **arr)
{
	double	number;

	number = ft_strtod(line, arr);
	if (number < lower)
	{
		ft_fprintf(2, BOLD_ORANGE"%s\n"RESET, ERRLINE);
		ft_fprintf(2, BOLD_ORANGE"RangeWarning\n\n"RESET);
		ft_fprintf(2, "%s is below lower limit\n", line);
		printf("lower limit: %.2f\n", lower);
		printf(BOLD_YELLOW"Value has been capped to lower limit\n"RESET);
		ft_fprintf(2, BOLD_ORANGE"%s\n"RESET, ERRLINE);
		return (lower);
	}
	if (number > upper)
	{
		ft_fprintf(2, BOLD_ORANGE"%s\n"RESET, ERRLINE);
		ft_fprintf(2, BOLD_ORANGE"RangeWarning\n\n"RESET);
		ft_fprintf(2, "%s is above upper limit\n", line);
		printf("upper limit: %.2f\n", upper);
		printf(BOLD_YELLOW"Value has been capped to upper limit\n"RESET);
		ft_fprintf(2, BOLD_ORANGE"%s\n"RESET, ERRLINE);
		return (lower);
	}
	return (number);
}

int	range_int(char *line, int lower, int upper)
{
	int	number;

	number = ft_rt_atoi(line, NULL);
	if (number < lower)
	{
		ft_fprintf(2, BOLD_ORANGE"%s\n"RESET, ERRLINE);
		ft_fprintf(2, BOLD_ORANGE"RangeWarning\n\n"RESET);
		ft_fprintf(2, "%s is below lower limit\n", line);
		printf("lower limit: %d\n", lower);
		printf(BOLD_YELLOW"Value has been capped to lower limit\n"RESET);
		ft_fprintf(2, BOLD_ORANGE"%s\n"RESET, ERRLINE);
		return (lower);
	}
	if (number > upper)
	{
		ft_fprintf(2, BOLD_ORANGE"%s\n"RESET, ERRLINE);
		ft_fprintf(2, BOLD_ORANGE"RangeWarning\n\n"RESET);
		ft_fprintf(2, "%s is above upper limit\n", line);
		printf("upper limit: %d\n", upper);
		printf(BOLD_YELLOW"Value has been capped to upper limit\n"RESET);
		ft_fprintf(2, BOLD_ORANGE"%s\n"RESET, ERRLINE);
		return (lower);
	}
	return (number);
}

/* int	range_int(char *line, int lower, int upper)
{
	int	number;

	number = ft_rt_atoi(line, NULL);
	if (number < lower || number > upper)
	{
		ft_fprintf(2, BOLD_RED"%s\n"RESET, ERRLINE);
		ft_fprintf(2, BOLD_RED"RangeError\n\n"RESET);
		ft_fprintf(2, "%s , is out of range\n", line);
		printf("lower limit: %d, upper limit: %d\n", lower, upper);
		err_template("Parameter out of specified range", line, NULL);
	}
	return (number);
} */
