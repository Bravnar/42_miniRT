#include "main.h"

bool	equal_color(t_color a, t_color b)
{
	return (equal(a.r, b.r) && \
			equal(a.g, b.g) && \
			equal(a.b, b.b));
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
			if (!equal(a.m[i][j], b.m[i][j]))
				return (false);
	}
	return (true);
}

bool	equal_inter(t_inter **a, t_inter **b)
{
	t_inter		*tmp_a;
	t_inter		*tmp_b;

	if (*b == NULL)
		return (!*a);
	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a && tmp_b)
	{
		if (!equal(tmp_a->i.t, tmp_b->i.t))
			return (false);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	if (tmp_a || tmp_b)
		return (false);
	return (true);
}
