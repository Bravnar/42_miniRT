#include "main.h"

t_inter	intersect_slice(t_inter *inter, int start, int end, int size)
{
	t_inter copy;
	int		i;

	copy.i = malloc(sizeof(double) * size);
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

void	insert_inter(t_inter left, t_inter right, t_inter *ret)
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
	if (right.count > 0)
		free(left.i);
	if (left.count > 0)
		free(right.i);
}

void	sort_inter(t_inter *inter)
{
	t_inter	ret;
	t_inter	left;
	t_inter	right;

	if (inter->count > 1)
	{
		left = intersect_slice(inter, 0, inter->count/2, inter->count/2);
		right = intersect_slice(inter, inter->count/2, inter->count, inter->count/2);
		sort_inter(&left);
		sort_inter(&right);
		ret.i = malloc(sizeof(double) * inter->count);
		if (!ret.i)
		{
			ret.count = 0;
			free(inter->i);
			inter = &ret;
			return ;
		}
		insert_inter(left, right, &ret);
	}
	if (inter->count > 0)
		free(inter->i);
	inter = &ret;
}
