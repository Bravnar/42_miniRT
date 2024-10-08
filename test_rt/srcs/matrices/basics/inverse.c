/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20/08/2024 08:12:43 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 09:59:29 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_invertible(t_matrix A)
{
	return (determinant(A, 4));
}

double	cofactor(t_matrix A, int r, int c, int size_M)
{
	int			i;
	int			j;
	int			k;
	int			l;
	t_matrix	sub;

	i = -1;
	k = 0;
	while (++i < size_M)
	{
		if (i == r)
			continue ;
		j = -1;
		l = 0;
		while (++j < size_M)
		{
			if (j == c)
				continue ;
			sub.m[k][l++] = A.m[i][j];
		}
		k++;
	}
	return (determinant(sub, size_M - 1));
}

t_matrix	inverse(t_matrix A, int size)
{
	int			r;
	int			c;
	double		det;
	t_matrix	inv;

	det = determinant(A, size);
	r = -1;
	while (++r < size)
	{
		c = -1;
		while (++c < size)
			inv.m[c][r] = cofactor(A, r, c, size) / det * pow(-1, c + r);
	}
	return (inv);
}
