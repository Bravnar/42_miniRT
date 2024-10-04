/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20/08/2024 08:12:43 by hmorand           #+#    #+#             */
/*   Updated: 20/08/2024 08:12:43 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_shear	shear(double numbers[6])
{
	t_shear	s;

	s.xy = numbers[0];
	s.xz = numbers[1];
	s.yx = numbers[2];
	s.yz = numbers[3];
	s.zx = numbers[4];
	s.zy = numbers[5];
	return (s);
}

t_matrix	shearing_matrix(t_shear sh)
{
	t_matrix	matrix;

	matrix = identity();
	matrix.m[0][1] = sh.xy;
	matrix.m[0][2] = sh.xz;
	matrix.m[1][0] = sh.yx;
	matrix.m[1][2] = sh.yz;
	matrix.m[2][0] = sh.zx;
	matrix.m[2][1] = sh.zy;
	return (matrix);
}

t_tup	shearing(t_tup point, t_shear sh)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = shearing_matrix(sh);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}

t_tup	inverse_shearing(t_tup point, t_shear sh)
{
	t_tup		transformed;
	t_matrix	transformation_matrix;

	transformation_matrix = inverse(shearing_matrix(sh), 4);
	transformed = matrix_mult_tup(transformation_matrix, point);
	return (transformed);
}
