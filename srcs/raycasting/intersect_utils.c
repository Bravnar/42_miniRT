#include "main.h"

void	empty_inter(t_inter *inter)
{
	if (inter->count > 0)
	{
		inter->count = 0;
		free(inter->i);
	}
	inter->i = NULL;
}
