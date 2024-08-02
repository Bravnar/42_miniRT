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

	new.t = 1;
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

	new.t = 1;
	new.r = c1.r - c2.r;
	new.g = c1.g - c2.g;
	new.b = c1.b - c2.b;
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

	new.t = 1;
	new.r = scalar * c2.r;
	new.g = scalar * c2.g;
	new.b = scalar * c2.b;
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

	new.t = 1;
	new.r = c1.r * c2.r;
	new.g = c1.g * c2.g;
	new.b = c1.b * c2.b;
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

	new.t = c1.t + (c1.t * (255 - c1.t) / 255);
	new.r = (c1.r * c1.t + c2.r * c2.t * (255 - c1.t) / 255) / new.t;
	new.g = (c1.g * c1.t + c2.g * c2.t * (255 - c1.t) / 255) / new.t;
	new.b = (c1.b * c1.t + c2.b * c2.t * (255 - c1.t) / 255) / new.t;
	return (new);
}
