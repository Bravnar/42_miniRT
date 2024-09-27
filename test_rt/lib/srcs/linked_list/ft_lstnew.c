/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:54:04 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/07 09:56:26 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_item;

	list_item = malloc(sizeof(t_list));
	if (!list_item)
		return (NULL);
	list_item->content = content;
	list_item->next = NULL;
	return (list_item);
}
