/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:56:08 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 15:56:08 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Adds two colors together.
 *
 * This function takes two colors as input and returns their sum.
 * Each component (red, green, blue) of the resulting color is the sum
 * of the corresponding components of the input colors.
 *
 * @param c1 The first color to add.
 * @param c2 The second color to add.
 * @return The resulting color after addition.
 */
t_color	color_add(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r + c2.r;
	new.g = c1.g + c2.g;
	new.b = c1.b + c2.b;
	return (new);
}

/**
 * Subtracts the color components of two t_color structures.
 *
 * @param c1 The first color structure.
 * @param c2 The second color structure.
 * @return A t_color structure containing the result of the subtraction.
 */
t_color	color_sub(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r - c2.r;
	new.g = c1.g - c2.g;
	new.b = c1.b - c2.b;
	add_hex_color(&new);
	return (new);
}

/**
 * Multiplies a color by a scalar value.
 *
 * @param scalar The scalar value to multiply the color by.
 * @param c2 The color to be multiplied.
 * @return The resulting color after multiplication.
 */
t_color	color_scalarmult(double scalar, t_color c2)
{
	t_color	new;

	new.r = scalar * c2.r;
	new.g = scalar * c2.g;
	new.b = scalar * c2.b;
	add_hex_color(&new);
	return (new);
}

/**
 * @brief Computes the product of two colors.
 *
 * This function takes two colors as input and returns their product.
 * The product is computed component-wise, meaning each color component
 * (red, green, blue) of the resulting color is the product of the corresponding
 * components of the input colors.
 *
 * @param c1 The first color.
 * @param c2 The second color.
 * @return The product of the two colors.
 */
t_color	color_product(t_color c1, t_color c2)
{
	t_color	new;

	new.r = (c1.r / 255 * c2.r / 255) * 255;
	new.g = (c1.g / 255 * c2.g / 255) * 255;
	new.b = (c1.b / 255 * c2.b / 255) * 255;
	add_hex_color(&new);
	return (new);
}

/**
 * Blends two colors together.
 *
 * @param c1 The first color.
 * @param c2 The second color.
 * @return The blended color.
 */
t_color	color_blend(t_color c1, t_color c2)
{
	t_color	new;

	new.r = (c1.r + c2.r) / 2;
	new.g = (c1.g + c2.g) / 2;
	new.b = (c1.b + c2.b) / 2;
	add_hex_color(&new);
	return (new);
}
