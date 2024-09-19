#include "main.h"

t_amb	fetch_amb(t_parse **head)
{
	t_parse	*tmp;
	t_amb	amb;

	tmp = *head;
	amb.ratio = 0;
	while (tmp)
	{
		if (tmp->type == AMBIENT)
		{
			amb.ratio = ft_strtod(tmp->line_split[0]);
			if (amb.ratio < 0.0 || amb.ratio > 1.0)
				err_template("AMB ratio out of range", tmp->line);
			amb.rgb = color_split(tmp->line_split[1]);
			break ;
		}
		tmp = tmp->next;
	}
	return (amb);
}
