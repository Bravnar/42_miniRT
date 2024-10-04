/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:05:46 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:06:02 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_invertible(t_matrix A)
{
	return (determinant(A, 4));
}

/**
 * @brief Computes the cofactor of a matrix element.
 *
 * This function calculates the cofactor of the element at the specified row
 * and column in the given matrix. The cofactor is used in the computation
 * of the inverse of a matrix.
 *
 * @param A The matrix for which the cofactor is to be computed.
 * @param r The row index of the element.
 * @param c The column index of the element.
 * @param size_M The size of the matrix (number of rows/columns).
 * @return The cofactor of the element at the specified position.
 */
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

/**
 * @brief Computes the inverse of a given matrix.
 *
 * This function takes a matrix `A` and its size, and returns
 * the inverse of the matrix.
 *
 * @param A The matrix to be inverted.
 * @param size The size of the matrix (number of rows/columns).
 * @return The inverse of the matrix `A`.
 */
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
