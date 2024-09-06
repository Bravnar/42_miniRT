#include "main.h"

/* ****************************************************************/
/*                                                                */
/*ADDING COLORS                                                   */
/*Can be used to:                                                 */
/*	- A ray of colored light is applied on a colored surface      */
/*                                                                */
/* ****************************************************************/

t_color	color_add(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r + c2.r;
	new.g = c1.g + c2.g;
	new.b = c1.b + c2.b;
	return (new);
}

/* ****************************************************************/
/*                                                                */
/*SUBTRACTING COLORS                                              */
/*Can be used to:                                                 */
/*	- ?                                                           */
/*                                                                */
/* ****************************************************************/

t_color	color_sub(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r - c2.r;
	new.g = c1.g - c2.g;
	new.b = c1.b - c2.b;
	add_hex_color(&new);
	return (new);
}

/* ****************************************************************/
/*                                                                */
/*SCALAR MULTIPLICATION COLOR                                     */
/*Can be used to:                                                 */
/*	- ?                                                           */
/*                                                                */
/* ****************************************************************/

t_color	color_scalarmult(double scalar, t_color c2)
{
	t_color	new;

	new.r = scalar * c2.r;
	new.g = scalar * c2.g;
	new.b = scalar * c2.b;
	add_hex_color(&new);
	return (new);
}

/* ****************************************************************/
/*                                                                */
/*MULTIPICATING COLORS (HADAMARD PRODUCT)                         */
/*Can be used to:                                                 */
/*	- ?                                                           */
/*                                                                */
/* ****************************************************************/

t_color	color_product(t_color c1, t_color c2)
{
	t_color	new;

	new.r = (c1.r / 255 * c2.r / 255) * 255;
	new.g = (c1.g / 255 * c2.g / 255) * 255;
	new.b = (c1.b / 255 * c2.b / 255) * 255;
	add_hex_color(&new);
	return (new);
}

/* ****************************************************************/
/*                                                                */
/*COLOR BLENDING (OPTIONAL - NOT SURE HOW TO USE IT YET)          */
/*Can be used to:                                                 */
/*	- superpose shapes with different levels of transparency      */
/*                                                                */
/*CAVEAT:                                                         */
/*	- This only works with flat shapes                            */
/* ****************************************************************/

t_color	color_blend(t_color c1, t_color c2)
{
	t_color	new;

	// new.t = 255;
	// new.r = c1.r * c2.r;
	// new.g = c1.g * c2.g;
	// new.b = c1.b * c2.b;
	new.r = (c1.r + c2.r) / 2;
	new.g = (c1.g + c2.g) / 2;
	new.b = (c1.b + c2.b) / 2;
	add_hex_color(&new);
	return (new);
}
