/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:55:36 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 14:56:18 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Applies a transformation matrix to a pattern.
 *
 * This function modifies the given pattern by applying the specified
 * transformation matrix to it. The transformation can include operations
 * such as translation, rotation, scaling, etc.
 *
 * @param pat A pointer to the pattern to be transformed.
 * @param transformation The transformation matrix to be applied to the pattern.
 */
static void	transform(t_pattern *pat, t_matrix transformation)
{
	pat->transformation = matrix_mult(pat->transformation, transformation);
	pat->inverse_transformation = matrix_mult(pat->inverse_transformation,
			inverse(transformation, 4));
}

/**
 * @brief Creates a default pattern with the specified color.
 *
 * This function initializes a pattern structure with the given color.
 *
 * @param a The color to be used for the pattern.
 * @return A pattern structure initialized with the specified color.
 */
t_pattern	pat_default(t_color a)
{
	t_pattern	pat;

	pat.colors[0] = a;
	pat.colors[1] = white();
	pat.transformation = identity();
	pat.inverse_transformation = identity();
	pat.transform = transform;
	pat.noise = 0.2;
	pat.scale = 0;
	pat.color_at = plain_pattern;
	return (pat);
}

/**
 * @brief Creates a pattern structure with specified colors,
 * pattern type, and transformation matrix.
 *
 * @param a The first color in the pattern.
 * @param b The second color in the pattern.
 * @param type The type of pattern (e.g., stripes, gradient, etc.).
 * @param trans The transformation matrix applied to the pattern.
 *
 * @return A t_pattern structure initialized with the given parameters.
 */
t_pattern	pattern(t_color a, t_color b, t_patt_type type, t_matrix trans)
{
	t_pattern	pat;

	pat.colors[0] = a;
	pat.colors[1] = b;
	pat.transformation = identity();
	pat.inverse_transformation = identity();
	pat.transform = transform;
	pat.noise = 0.2;
	pat.scale = 0;
	pat.transform(&pat, trans);
	if (type == PLAIN)
		pat.color_at = plain_pattern;
	else if (type == STRIPE)
		pat.color_at = stripe_pattern;
	else if (type == GRADIENT)
		pat.color_at = gradient_pattern;
	return (pat);
}
