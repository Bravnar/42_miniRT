/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:07:10 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:07:48 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Compares two matrices for equality.
 *
 * This function takes two matrices, A and B, and compares
 * them element by element to determine if they are equal.
 *
 * @param A The first matrix to compare.
 * @param B The second matrix to compare.
 * @return true if the matrices are equal, false otherwise.
 */
bool	matrix_compare(t_matrix A, t_matrix B)
{
	int	r;
	int	c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			if (A.m[r][c] != B.m[r][c])
				return (false);
		}
	}
	return (true);
}

/**
 * Multiplies two matrices A and B.
 *
 * @param A The first matrix.
 * @param B The second matrix.
 * @return The resulting matrix after multiplication.
 */
t_matrix	matrix_mult(t_matrix A, t_matrix B)
{
	t_matrix	result;
	int			r;
	int			c;
	int			i;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			i = -1;
			result.m[r][c] = 0;
			while (++i < 4)
				result.m[r][c] += A.m[r][i] * B.m[i][c];
		}
	}
	return (result);
}

/**
 * Multiplies a matrix by a column vector.
 *
 * @param A The matrix to be multiplied.
 * @param b The column vector to be multiplied.
 * @return The resulting column vector after multiplication.
 */
t_column	matrix_mult_col(t_matrix A, t_column b)
{
	t_column	result;
	int			r;
	int			i;

	r = -1;
	while (++r < 4)
	{
		i = -1;
		result.m[r] = 0;
		while (++i < 4)
			result.m[r] += A.m[r][i] * b.m[i];
	}
	return (result);
}

/**
 * Multiplies a matrix by a tuple.
 *
 * @param A The matrix to be multiplied.
 * @param b The tuple to be multiplied.
 * @return The resulting tuple after multiplication.
 */
t_tup	matrix_mult_tup(t_matrix A, t_tup b)
{
	t_column	temp;
	t_tup		result;
	int			r;

	r = -1;
	while (++r < 4)
	{
		temp.m[r] = A.m[r][0] * b.x;
		temp.m[r] += A.m[r][1] * b.y;
		temp.m[r] += A.m[r][2] * b.z;
		temp.m[r] += A.m[r][3] * b.w;
	}
	result.x = temp.m[0];
	result.y = temp.m[1];
	result.z = temp.m[2];
	result.w = temp.m[3];
	return (result);
}
