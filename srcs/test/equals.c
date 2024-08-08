#include "main.h"


bool	equal_color(t_color a, t_color b)
{
	return (equal(a.r, b.r) && \
			equal(a.g, b.g) && \
			equal(a.b, b.b) && \
			equal(a.t*255, b.t));
}

bool	equal_tuple(t_tup a, t_tup b)
{
	return (equal(a.x, b.x) && \
			equal(a.y, b.y) && \
			equal(a.z, b.z) && \
			equal(a.w, b.w));
}

bool	equal_matrix(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (!equal(a.M[i][j], b.M[i][j]))
				return (false);
	}
	return (true);
}


