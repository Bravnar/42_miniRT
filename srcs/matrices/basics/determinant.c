/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:00:28 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:04:43 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Extracts a submatrix from the given matrix by
 * excluding a specified row and column.
 *
 * This function creates a submatrix from the input matrix `A`
 * by excluding the row and column specified by the `size`
 * and `ex` parameters, respectively. The resulting submatrix is used
 * for various matrix operations, such as calculating the determinant.
 *
 * @param A The original matrix from which the submatrix is to be extracted.
 * @param size The size of the matrix `A`.
 * @param ex The index of the row and column to be excluded from the submatrix.
 * @return The resulting submatrix after excluding the specified row and column.
 */
t_matrix	sub(t_matrix A, int size, int ex)
{
	t_matrix	sub;
	int			r;
	int			c;
	int			i;
	int			j;

	r = 0;
	i = 0;
	while (++r < size + 1)
	{
		c = -1;
		j = 0;
		while (++c < size + 1)
		{
			if (c == ex)
				continue ;
			sub.m[i][j++] = A.m[r][c];
		}
		i++;
	}
	return (sub);
}

/**
 * @brief Checks if a given matrix is triangular.
 *
 * This function determines whether the provided matrix `A` of given `size`
 * is a triangular matrix. A triangular matrix is one that is either upper
 * triangular or lower triangular.
 *
 * @param A The matrix to be checked.
 * @param size The size of the matrix (number of rows/columns).
 * @return true if the matrix is triangular, false otherwise.
 */
bool	is_triangular(t_matrix A, int size)
{
	int		i;
	int		j;
	bool	lower;
	bool	upper;

	i = -1;
	lower = true;
	upper = true;
	while (++i < size - 1)
	{
		j = 0 + i;
		if (!lower && !upper)
			break ;
		while (++j < size)
		{
			if (!lower && !upper)
				break ;
			if (upper)
				upper = !equal(A.m[i][j], 0);
			if (lower)
				lower = !equal(A.m[j][i], 0);
		}
	}
	return (lower || upper);
}

/**
 * @brief Contains the function to check if a matrix has a zero row or column.
 *
 * This file includes the implementation of a function that determines whether
 * a given matrix has any row or column that is entirely composed of zeros.
 *
 * @param A The matrix to be checked.
 * @param size The size of the matrix (number of rows/columns).
 * @return true if the matrix has a zero row or column, false otherwise.
 */
bool	has_zero_row_column(t_matrix A, int size)
{
	int	i;
	int	j;
	int	sum_r;
	int	sum_c;

	i = -1;
	sum_c = 1;
	sum_r = 1;
	while (++i < size && sum_r && sum_c)
	{
		sum_c = 0;
		sum_r = 0;
		j = -1;
		while (++j < size)
		{
			sum_r += A.m[i][j];
			sum_c += A.m[j][i];
		}
	}
	return (equal(sum_c, 0) || equal(sum_r, 0));
}

/**
 * @brief Computes the product of the diagonal elements of a matrix.
 *
 * This function calculates the product of the diagonal elements of a given
 * square matrix A of a specified size.
 *
 * @param A The matrix for which the diagonal product is to be computed.
 * @param size The size of the matrix (number of rows or
 * columns, since it is square).
 * @return The product of the diagonal elements of the matrix.
 */
double	diagonal_product(t_matrix A, int size)
{
	int	i;
	int	product;

	i = -1;
	product = 1;
	while (++i < size)
		product *= A.m[i][i];
	return (product);
}

/**
 * @brief Calculates the determinant of a matrix.
 *
 * This function computes the determinant of a square matrix of a given size.
/**
 * Calculates the determinant of a given matrix.
 *
 * This function computes the determinant of a matrix using recursion and
 * several optimizations:
 * - If the matrix is triangular, it returns
 * 	 the product of the diagonal elements.
 * - If the matrix has a zero row or column, it returns 0.
 * - For 2x2 matrices, it directly computes the determinant.
 * - For larger matrices, it recursively computes the determinant
 * 	 using cofactor expansion.
 *
 * @param A The matrix for which the determinant is to be calculated.
 * @param size The size of the matrix (number of rows/columns).
 * @return The determinant of the matrix.
 */
double	determinant(t_matrix A, int size)
{
	int			i;
	double		result;
	t_matrix	subm;

	if (is_triangular(A, size))
		return (diagonal_product(A, size));
	if (has_zero_row_column(A, size))
		return (0);
	i = -1;
	result = 0;
	if (size == 2)
		return (A.m[0][0] * A.m[1][1] - A.m[0][1] * A.m[1][0]);
	while (++i < size)
	{
		if (!A.m[0][i])
			continue ;
		subm = sub(A, size - 1, i);
		result += pow(-1, i) * determinant(subm, size - 1) * A.m[0][i];
	}
	return (result);
}
