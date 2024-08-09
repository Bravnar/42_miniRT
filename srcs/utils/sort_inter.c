#include "main.h"

t_inter	intersect_slice(t_inter *inter, int start, int end)
{
	t_inter	copy;
	int		i;
	int		size;

	size = end - start;
	copy.i = malloc(sizeof(t_intersection) * size);
	if (!copy.i)
	{
		copy.count = 0;
		return (copy);
	}
	i = 0;
	while (start < end)
		copy.i[i++] = inter->i[start++];
	copy.count = size;
	return (copy);
}

void	insert_inter(t_inter left, t_inter right, t_inter *ret, t_inter inter)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < right.count && j < left.count)
	{
		if (right.i[i].t > left.i[j].t)
			ret->i[k++] = left.i[j++];
		else
			ret->i[k++] = right.i[i++];
	}
	while (i < right.count)
		ret->i[k++] = right.i[i++];
	while (j < left.count)
		ret->i[k++] = left.i[j++];
	ret->count = inter.count;
	if (right.count > 0)
		free(right.i);
	if (left.count > 0)
		free(left.i);
}

t_inter	sort_inter(t_inter inter)
{
	t_inter	ret;
	t_inter	left;
	t_inter	right;

	if (inter.count <= 1)
		return (inter);
	ret.i = malloc(sizeof(t_intersection) * inter.count);
	if (!ret.i)
	{
		ret.count = 0;
		return (ret);
	}
	left = intersect_slice(&inter, 0, inter.count / 2);
	right = intersect_slice(&inter, inter.count / 2, inter.count);
	left = sort_inter(left);
	right = sort_inter(right);
	insert_inter(left, right, &ret, inter);
	free(inter.i);
	return (ret);
}
