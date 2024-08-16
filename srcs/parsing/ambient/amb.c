#include "main.h"

static void	get_amb_rgb(char *str)
{
	char	**color_split;
	t_amb	*a;
	int		r;
	int		g;
	int		b;
	
	a = &get_scene()->amb;
	color_split = ft_split(str, ',');
	r = ft_atoi(color_split[0]);
	g = ft_atoi(color_split[1]);
	b = ft_atoi(color_split[2]);
	a->rgb = color(r, g, b);
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
