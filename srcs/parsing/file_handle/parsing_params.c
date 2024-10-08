/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:46:10 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/20 09:14:41 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_obj_params(t_parse *tmp)
{
	if (!ft_strcmp(tmp->id, "pl") && tmp->count != 3)
		add_error(tmp->line, M_PL_PARAMETERS);
	else if (!ft_strcmp(tmp->id, "sp") && tmp->count != 3)
		add_error(tmp->line, M_SP_PARAMETERS);
	else if (!ft_strcmp(tmp->id, "cy") && tmp->count != 5)
		add_error(tmp->line, M_CY_PARAMETERS);
}

void	check_params(t_file *file)
{
	t_parse	*tmp;

	tmp = file->parse;
	while (tmp)
	{
		if (tmp->type == WINDOW && tmp->count != 2)
			add_error(tmp->line, M_R_OVER_PARAM);
		else if (tmp->type == AMBIENT && tmp->count != 2)
			add_error(tmp->line, M_A_OVER_PARAM);
		else if (tmp->type == CAMERA && tmp->count != 3)
			add_error(tmp->line, M_C_OVER_PARAM);
		else if (tmp->type == LIGHTS && tmp->count != 2)
			add_error(tmp->line, M_L_OVER_PARAM);
		else if (tmp->type == OBJECTS)
			check_obj_params(tmp);
		tmp = tmp->next;
	}
}

void	check_obj_params_bonus(t_parse *tmp)
{
	if (!ft_strcmp(tmp->id, "pl") && tmp->count != 9)
		add_error(tmp->line, M_PL_PARAMETERS);
	else if (!ft_strcmp(tmp->id, "sp") && tmp->count != 9)
		add_error(tmp->line, M_SP_PARAMETERS);
	else if (!ft_strcmp(tmp->id, "cy") && tmp->count != 11)
		add_error(tmp->line, M_CY_PARAMETERS);
}

void	check_params_bonus(t_file *file)
{
	t_parse	*tmp;

	tmp = file->parse;
	while (tmp)
	{
		if (tmp->type == WINDOW && tmp->count != 2)
			add_error(tmp->line, M_R_OVER_PARAM);
		else if (tmp->type == AMBIENT && tmp->count != 2)
			add_error(tmp->line, M_A_OVER_PARAM);
		else if (tmp->type == CAMERA && tmp->count != 3)
			add_error(tmp->line, M_C_OVER_PARAM);
		else if (tmp->type == LIGHTS && tmp->count != 3)
			add_error(tmp->line, M_L_OVER_PARAM);
		else if (tmp->type == OBJECTS)
			check_obj_params_bonus(tmp);
		tmp = tmp->next;
	}
}
