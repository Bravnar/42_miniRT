#include "main.h"

void	empty_inter(t_inter *inter)
{
	inter->count = 0;
	free(inter->i);
	inter->i = NULL;
}
