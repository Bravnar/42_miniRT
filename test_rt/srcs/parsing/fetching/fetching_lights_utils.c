/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetching_lights_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:45:09 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 10:45:10 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_light_node_front(t_light *light, t_light **head)
{
	light->next = *head;
	*head = light;
}

void	remove_first_light(t_light **head)
{
	t_light	*tmp;

	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
