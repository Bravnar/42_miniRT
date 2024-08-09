#include "main.h"

static void	get_amb_rgb(char *str)
{
	char	**color_split;
	int		r;
	int		g;
	int		b;

	get_scene()->amb.rgb = color(r, g, b);
	r = ft_atoi(color_split[0]);
	g = ft_atoi(color_split[1]);
	b = ft_atoi(color_split[2]);
	color_split = ft_split(str, ',');
	ft_free_arr(color_split);
}

void	populate_amb(void)
{
	t_parse	*tmp;
	double	*ratio;

	ratio = &get_scene()->amb.ratio;
	tmp = get_scene()->file.parse;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line_split[0], "A"))
		{
			*ratio = ft_strtod(tmp->line_split[1]);
			if (*ratio < 0.0 || *ratio > 1.0)
			{
				printf("error with ratio\n");
				exit(1);
			}
			get_amb_rgb(tmp->line_split[2]);
			break ;
		}
		tmp = tmp->next;
	}
}
