/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetching_amb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:44:57 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 12:09:24 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				err_template("AMB ratio out of range", tmp->line, NULL);
			amb.rgb = color_split(tmp->line_split[1]);
			break ;
		}
		tmp = tmp->next;
	}
	return (amb);
}
