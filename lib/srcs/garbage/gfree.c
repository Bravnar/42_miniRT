/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:21:18 by hmorand           #+#    #+#             */
/*   Updated: 2024/03/27 20:21:24 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

/* Gracefully adapted from our very own rude-jes */
/* (Github: https://github.com/RPDJF/betterft/)  */

#include "../../includes/my_lib.h"

void	gfree(void *address)
{
	t_garbage	**collector;
	t_garbage	*todel;

	collector = getgarbage();
	todel = *collector;
	while (todel && todel->content != address)
		todel = todel->next;
	if (!todel)
		free(address);
	else
	{
		if (todel->previous)
			todel->previous->next = todel->next;
		else
			*collector = todel->next;
		if (todel->next)
			todel->next->previous = todel->previous;
		free(todel->content);
		free(todel);
	}
	return ;
}
