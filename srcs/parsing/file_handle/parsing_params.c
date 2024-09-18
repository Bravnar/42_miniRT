#include "main.h"

void	check_obj_params(t_parse *tmp)
{
	if (!ft_strcmp(tmp->id, "pl") && tmp->count > 3)
		err_template(M_PL_PARAMETERS, tmp->line);
	else if (!ft_strcmp(tmp->id, "sp") && tmp->count > 3)
		err_template(M_SP_PARAMETERS, tmp->line);
	else if (!ft_strcmp(tmp->id, "cy") && tmp->count > 5)
		err_template(M_CY_PARAMETERS, tmp->line);
}

void	check_params(t_file *file)
{
	t_parse	*tmp;

	tmp = file->parse;
	while (tmp)
	{
		if (tmp->type == WINDOW && tmp->count != 2)
			err_template(M_R_OVER_PARAM, tmp->line);
		else if (tmp->type == AMBIENT && tmp->count != 2)
			err_template(M_A_OVER_PARAM, tmp->line);
		else if (tmp->type == CAMERA && tmp->count != 3)
			err_template(M_C_OVER_PARAM, tmp->line);
		else if (tmp->type == LIGHTS && tmp->count != 2)
			err_template(M_L_OVER_PARAM, tmp->line);
		else if (tmp->type == OBJECTS)
			check_obj_params(tmp);
		tmp = tmp->next;
	}
}

void	check_obj_params_bonus(t_parse *tmp)
{
	if (!ft_strcmp(tmp->id, "pl") && tmp->count != 9)
		err_template(M_PL_PARAMETERS, tmp->line);
	else if (!ft_strcmp(tmp->id, "sp") && tmp->count != 9)
		err_template(M_SP_PARAMETERS, tmp->line);
	else if (!ft_strcmp(tmp->id, "cy") && tmp->count != 11)
		err_template(M_CY_PARAMETERS, tmp->line);
}

void	check_params_bonus(t_file *file)
{
	t_parse	*tmp;

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
			check_obj_params_bonus(tmp);
		tmp = tmp->next;
	}
}
