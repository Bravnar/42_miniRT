/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:45:59 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 10:46:00 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	counter_single(char c, t_file *file)
{
	if (c == 'R')
		file->count.r++;
	else if (c == 'A')
		file->count.a++;
	else if (c == 'C')
		file->count.c++;
	else if (c == 'L')
		file->count.l++;
}

static void	counter_double(char *str, t_file *file)
{
	char	*tmp;

	tmp = ft_strdup(str);
	if (!ft_strcmp("pl", tmp))
		file->count.pl++;
	if (!ft_strcmp("sp", tmp))
		file->count.sp++;
	if (!ft_strcmp("cy", tmp))
		file->count.cy++;
	if (!ft_strcmp("cu", tmp))
		file->count.cu++;
	free(tmp);
}

static void	counter_breakdown(char *cptr, t_file *file)
{
	if (ft_strchr(GOOD_ID_SINGLE, cptr[0]))
		counter_single(cptr[0], file);
	else
		counter_double(cptr, file);
}

void	count_identifier(t_parse **head, t_file *file)
{
	t_parse	*tmp;
	char	*cptr;

	tmp = *head;
	cptr = NULL;
	while (tmp)
	{
		if (tmp->id)
		{
			cptr = ft_strstr(GOOD_ID, tmp->id);
			if (cptr)
				counter_breakdown(cptr, file);
		}
		tmp = tmp->next;
	}
}

void	check_count(t_file *file)
{
	count_identifier(&file->parse, file);
	if (file->count.a < 1 || \
		file->count.c < 1 || \
		file->count.l < 1)
		err_template(M_ACL_MISSING, NULL);
	if (file->count.a > 1)
		err_template(M_TOO_MANY_A, NULL);
	if (file->count.c > 1)
		err_template(M_TOO_MANY_C, NULL);
	if (file->count.r > 1)
		err_template(M_TOO_MANY_R, NULL);
	if (file->count.l > 1)
		err_template(M_TOO_MANY_L, NULL);
}
