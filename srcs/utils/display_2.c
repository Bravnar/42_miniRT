#include "main.h"

void	print_inter(t_inter i)
{
	int	j;

	printf("count of intersections = %d\n", i.count);
	if (i.count == 0)
	{
		printf("No intersections\n");
		return ;
	}
	printf("Intersections:\n");
	j = 0;
	while (j < i.count)
	{
		printf("\t- t: %f\n", i.i[j].t);
		j++;
	}
}

void	print_intersection(t_intersection i)
{
	if (i.t == -1)
	{
		printf("No intersection\n");
		return ;
	}
	printf("Intersection.t: %.2f\n", i.t);
}
