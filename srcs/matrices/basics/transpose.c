/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:08:08 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:08:08 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Transpose a given matrix.
 *
 * This function takes a matrix A as input and returns its transpose.
 *
 * @param A The matrix to be transposed.
 * @return The transposed matrix.
 */
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
