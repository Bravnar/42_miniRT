/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetching_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:45:34 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/20 09:01:50 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_res_limits(t_rwin res, char *line)
{
	if (res.x < 0 || res.y < 0)
		add_error(line, "Resolution too small");
	if (res.x > WIN_X_MAX || res.y > WIN_Y_MAX)
		add_error(line, "Resolution too large");
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
			res.x = ft_rt_atoi(tmp->line_split[0]);
			res.y = ft_rt_atoi(tmp->line_split[1]);
			check_res_limits(res, tmp->line);
			break ;
		}
		tmp = tmp->next;
	}
	return (res);
}
