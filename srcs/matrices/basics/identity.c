/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:05:07 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:05:18 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Creates an identity matrix.
 *
 * This function generates a 4x4 identity matrix.
 *
 * @return A 4x4 identity matrix.
 */
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
