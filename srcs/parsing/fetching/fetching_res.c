#include "main.h"

void	check_res_limits(t_rwin res, char *line)
{
	if (res.x < 0 || res.y < 0)
		err_template("Resolution too small", line);
	if (res.x > WIN_X_MAX || res.y > WIN_Y_MAX)
		err_template("Resolution too large", line);
}

t_rwin	fetch_res(t_parse **head)
{
	t_parse *tmp;
	t_rwin	res;

	tmp = *head;
	res.x = WIN_X_DEFAULT;
	res.y = WIN_Y_DEFAULT;
	while (tmp)
	{
		if (tmp->type == WINDOW)
		{
			res.x = ft_atoi(tmp->line_split[0]);
			res.y = ft_atoi(tmp->line_split[1]);
			check_res_limits(res, tmp->line);
			break ;
		}
		tmp = tmp->next;
	}
	return (res);
}