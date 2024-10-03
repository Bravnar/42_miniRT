/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:56:17 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 15:56:17 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Initializes a t_color structure with the given RGB values.
 *
 * @param r The red component of the color [0.0, 255.0].
 * @param g The green component of the color [0.0, 255.0].
 * @param b The blue component of the color [0.0, 255.0].
 * @return A t_color structure initialized with the specified RGB values.
 */
t_color	color(double r, double g, double b)
{
	t_color	new;

	new.r = r;
	new.g = g;
	new.b = b;
	new.hex = nadd_hex_color(r, g, b);
	return (new);
}

/**
 * @brief Adds a hexadecimal color to the given color structure.
 *
 * This function takes a pointer to a t_color structure and adds a color
 * represented in hexadecimal format to it.
 *
 * @param c A pointer to the t_color structure where the
 * hexadecimal color will be added.
 */
void	add_hex_color(t_color *c)
{
	if (c->r > 255)
		c->r = 255;
	if (c->g > 255)
		c->g = 255;
	if (c->b > 255)
		c->b = 255;
	c->hex = ((int) c->r << 16 | \
			(int) c->g << 8 | \
			(int) c->b);
}

/**
 * @brief Combines red, green, and blue color components into a single
 * hexadecimal color value.
 *
 * This function takes individual red, green, and blue color components,
 * each ranging from 0 to 255, and combines them into a single
 * integer representing the color in hexadecimal format.
 *
 * @param r The red color component (0-255).
 * @param g The green color component (0-255).
 * @param b The blue color component (0-255).
 * @return The combined hexadecimal color value.
 */
int	nadd_hex_color(int r, int g, int b)
{
	int	hex;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	hex = (r << 16 | \
			g << 8 | \
			b);
	return (hex);
}

void	print_color(t_color c)
{
	printf("(%.4f, %.4f, %.4f) ", c.r / 255, c.g / 255, c.b / 255);
	printf("\n");
}
