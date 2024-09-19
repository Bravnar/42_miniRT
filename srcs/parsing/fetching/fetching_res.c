/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetching_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:45:34 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 17:37:18 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_res_limits(t_rwin res, char *line)
{
	if (res.x < 0 || res.y < 0)
		err_template("Resolution too small", ft_strdup(line), NULL);
	if (res.x > WIN_X_MAX || res.y > WIN_Y_MAX)
		err_template("Resolution too large", ft_strdup(line), NULL);
}

t_rwin	fetch_res(t_parse **head)
{
	t_parse	*tmp;
	t_rwin	res;

	tmp = *head;
	res.x = WIN_X_DEFAULT;
	res.y = WIN_Y_DEFAULT;
	while (tmp)
	{
		if (tmp->type == WINDOW)
		{
			res.x = ft_rt_atoi(tmp->line_split[0], tmp->line_split);
			res.y = ft_rt_atoi(tmp->line_split[1], tmp->line_split);
			check_res_limits(res, tmp->line);
			break ;
		}
		tmp = tmp->next;
	}
	return (res);
}
