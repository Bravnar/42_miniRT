/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20/08/2024 08:15:18 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 09:58:33 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_matrix	identity(void)
{
	int			r;
	int			c;
	t_matrix	i;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			if (c == r)
				i.m[r][c] = 1;
			else
				i.m[r][c] = 0;
		}
	}
	return (i);
}
