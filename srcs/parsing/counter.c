#include "main.h"

static void	counter_single(char	c)
{
	if (c == 'R')
		get_scene()->count.r++;
	else if(c == 'A')
		get_scene()->count.a++;
	else if (c == 'C')
		get_scene()->count.c++;
	else if (c == 'L')
		get_scene()->count.l++;
}

static void	counter_double(char *str)
{
	char	tmp[2];

	tmp[0] = str[0];
	tmp[1] = str[1];
	tmp[2] = '\0';
	if (!ft_strcmp("pl", tmp))
		get_scene()->count.pl++;
	if (!ft_strcmp("sp", tmp))
		get_scene()->count.sp++;
	if (!ft_strcmp("cy", tmp))
		get_scene()->count.cy++;
	if (!ft_strcmp("cu", tmp))
		get_scene()->count.cu++;
}

static void	counter_breakdown(char *cptr)
{
	if (ft_strchr(GOOD_ID_SINGLE, cptr[0]))
		counter_single(cptr[0]);
	else
		counter_double(cptr);
}

void	count_identifier(t_parse **head)
{
	t_parse	*tmp;
	char	*cptr;

	tmp = *head;
	cptr = NULL;
	while (tmp)
	{
		if (tmp->line_split && tmp->line_split[0])
		{
			cptr = ft_strstr(GOOD_ID, tmp->line_split[0]);
			if (cptr)
				counter_breakdown(cptr);
		}
		tmp = tmp->next;
	}
}

void	check_count(void)
{
	count_identifier(&get_scene()->file.parse);
	if (get_scene()->count.a < 1 || \
		get_scene()->count.c < 1 || \
		get_scene()->count.l < 1)
		err_handler(ACL_MISSING);
	if (get_scene()->count.a > 1)
		err_handler(TOO_MANY_A);
	if (get_scene()->count.c > 1)
		err_handler(TOO_MANY_C);
	if (get_scene()->count.r > 1)
		err_handler(TOO_MANY_R);
}
