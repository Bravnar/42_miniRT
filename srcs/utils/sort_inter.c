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

void	insert_inter(t_inter *left, t_inter *right, t_inter *ret, t_inter inter)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < right->count && j < left->count)
	{
		if (right->i[i].t > left->i[j].t)
			ret->i[k++] = left->i[j++];
		else
			ret->i[k++] = right->i[i++];
	}
	while (i < right->count)
		ret->i[k++] = right->i[i++];
	while (j < left->count)
		ret->i[k++] = left->i[j++];
	ret->count = inter.count;
	// if (right->count > 0)
	empty_inter(right);
	// if (left->count > 0)
	empty_inter(left);
}

bool	is_sorted(t_inter inter)
{
	int	i;

	i = 0;
	while (i < inter.count - 1)
	{
		if (inter.i[i].t > inter.i[i + 1].t)
			return (false);
		i++;
	}
	return (true);
}

t_inter	sort_inter(t_inter inter)
{
	t_inter	ret;
	t_inter	left;
	t_inter	right;

	if (inter.count <= 1 || is_sorted(inter))
		return (inter);
	ret.i = malloc(sizeof(t_intersection) * inter.count);
	if (!ret.i)
	{
		empty_inter(&ret);
		return (ret);
	}
	left = intersect_slice(&inter, 0, inter.count / 2);
	right = intersect_slice(&inter, inter.count / 2, inter.count);
	left = sort_inter(left);
	right = sort_inter(right);
	insert_inter(&left, &right, &ret, inter);
	empty_inter(&inter);
	return (ret);
}
