/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bravnar <bravnar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:28:21 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/24 13:54:03 by bravnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static t_list	*ft_lstnew_strict(void *content)
{
	t_list	*list_item;

	list_item = malloc(sizeof(t_list));
	if (!list_item)
	{
		free(content);
		return (NULL);
	}
	list_item->content = content;
	list_item->next = NULL;
	return (list_item);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_elem;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	new_list_elem = NULL;
	while (lst)
	{
		new_list_elem = ft_lstnew_strict(f(lst->content));
		if (!new_list_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!new_list)
			new_list = new_list_elem;
		else
			ft_lstadd_back(&new_list, new_list_elem);
		lst = lst->next;
	}
	return (new_list);
}
