/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 30/08/2024 13:47:24 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:07:16 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_inter(t_inter **i)
{
	t_inter	*tmp;

	if (i == NULL)
	{
		printf("No intersections\n");
		return ;
	}
	printf("Intersections:\n");
	tmp = *i;
	while (tmp)
	{
		printf("\t- t: %f\n", tmp->i.t);
		tmp = tmp->next;
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
