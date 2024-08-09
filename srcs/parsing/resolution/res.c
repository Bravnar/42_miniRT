#include "main.h"

static int	check_rwin_limits(void)
{
	if (get_scene()->win.x < 0 || get_scene()->win.x > WIN_X_MAX)
		return (0);
	if (get_scene()->win.y < 0 || get_scene()->win.y > WIN_Y_MAX)
		return (0);
	return (1);
}

void	populate_rwin(void)
{
	t_parse	*tmp;

	tmp = get_scene()->file.parse;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line_split[0], "R"))
		{
			if (ft_arr_len(tmp->line_split) != 3)
			{
				printf("rwin too many parameters\n");
				exit (1);
			}
			get_scene()->win.x = ft_atoi(tmp->line_split[1]);
			get_scene()->win.y = ft_atoi(tmp->line_split[2]);
			if (!check_rwin_limits())
			{
				printf("window size error\n");
				exit (1);
			}
			break ;
		}
		tmp = tmp->next;
	}
}
