#include "main.h"

t_tup	get_light_point(char *str)
{
	char	**tup_split;
	t_tup	tup;

	tup_split = ft_split(str, ',');
	tup = point(ft_strtod(tup_split[0]),
				ft_strtod(tup_split[1]),
				ft_strtod(tup_split[2]));
	ft_free_arr(tup_split);
	return (tup);
}

t_color	get_light_rgb(char *str)
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

void	populate_light(void)
{
	t_parse	*tmp;
	t_light	*node;
	t_tup	tup;
	t_color	rgb;

	tmp = get_scene()->file.parse;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line_split[0], "L"))
		{
			tup	= get_light_point(tmp->line_split[1]);
			rgb = get_light_rgb(tmp->line_split[3]);
			node = new_light_node(tup, ft_strtod(tmp->line_split[2]), rgb);
			add_light_node(&get_scene()->light, node);
		}
		tmp = tmp->next;
	}
}