#include "main.h"

bool	equal(double a, double b)
{
	double	diff;

	diff = a - b;
	if (diff >= 0)
		return (diff < EPSILON);
	else
		return (diff > -EPSILON);
}
