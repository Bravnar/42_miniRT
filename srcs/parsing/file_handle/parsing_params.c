#include "main.h"

void	check_obj_params(t_parse *tmp)
{
	if (!ft_strcmp(tmp->id, "pl") && tmp->count > 3)
		tmp->is_bonus = true;
	else if (!ft_strcmp(tmp->id, "sp") && tmp->count > 3)
		tmp->is_bonus = true;
	else if (!ft_strcmp(tmp->id, "cy") && tmp->count > 5)
		tmp->is_bonus = true;
	else if (!ft_strcmp(tmp->id, "cu") && tmp->count > 6)
		tmp->is_bonus = true;
}

void	check_params(t_file *file)
{
	t_parse *tmp;

	tmp = file->parse;
	while (tmp)
	{
		if (tmp->type == WINDOW && tmp->count != 2)
			err_template(M_R_OVER_PARAM, tmp->line);
		else if (tmp->type == AMBIENT && tmp->count != 2)
			err_template(M_A_OVER_PARAM, tmp->line);
		else if (tmp->type == CAMERA && tmp->count != 3)
			err_template(M_C_OVER_PARAM, tmp->line);
		else if (tmp->type == LIGHTS && tmp->count != 3)
			err_template(M_L_OVER_PARAM, tmp->line);
		else if (tmp->type == OBJECTS)
			check_obj_params(tmp);
		tmp = tmp->next;
	}
}
