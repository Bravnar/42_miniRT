#include "main.h"

void free_inter_nodes(t_inter *inters)
{
	t_inter *tmp;

	if (!inters)
		return;
	while (inters)
	{
		tmp = inters;
		inters = inters->next;
		free(tmp);
	}
	tmp = NULL;
}
