/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20/08/2024 08:15:18 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 09:59:20 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_matrix	transpose(t_matrix A)
{
	t_matrix	t;
	int			r;
	int			c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
			t.m[c][r] = A.m[r][c];
	}
	return (t);
}
