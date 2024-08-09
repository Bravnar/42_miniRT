#include "main.h"

void	free_inter(t_inter inter)
{
	if (inter.i != NULL)
	{
		free(inter.i);
		inter.i = NULL;
	}
}
