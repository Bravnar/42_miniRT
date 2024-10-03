/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:19:34 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:20:35 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Frees the memory allocated for the intersection nodes.
 *
 * This function takes a pointer to an intersection node structure and
 * deallocates the memory associated with it, ensuring that all resources
 * are properly released.
 *
 * @param inters Pointer to the intersection node structure to be freed.
 */
void	free_inter_nodes(t_inter *inters)
{
	t_inter	*tmp;

	if (!inters)
		return ;
	while (inters)
	{
		tmp = inters;
		inters = inters->next;
		free(tmp);
	}
	inters = NULL;
	tmp = NULL;
}

/**
 * @brief Appends a new intersection node
 * to the end of the intersection linked list.
 *
 * This function takes a pointer to the head of
 * the intersection linked list and a new intersection node,
 * and appends the new node to the end of the list.
 *
 * @param head A double pointer to the head of the intersection linked list.
 * @param node A pointer to the new intersection node to be appended.
 */
void	append_inter_node(t_inter **head, t_inter *node)
{
	t_inter	*tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

/**
 * @brief Retrieves the last node in a linked list of intersections.
 *
 * This function traverses the linked list of intersections starting from the
 * head node and returns the last node in the list.
 *
 * @param head A double pointer to the head node of the linked list.
 * @return A pointer to the last node in the linked list,
 * or NULL if the list is empty.
 */
t_inter	*last_inter_node(t_inter **head)
{
	t_inter	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/**
 * @brief Checks if the given shape is in the intersection list.
 *
 * This function determines whether the specified shape is present in the
 * intersection list pointed to by `xs`.
 *
 * @param xs A pointer to the intersection list.
 * @param shape A pointer to the shape object to check for in
 * the intersection list.
 * @return true if the shape is in the intersection list, false otherwise.
 */
bool	in_inter(t_inter **xs, t_obj *shape)
{
	t_inter	*tmp;

	tmp = *xs;
	while (tmp)
	{
		if (tmp->i.shape->id == shape->id)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	equal_intersect(t_intersection a, t_intersection b)
{
	return (a.t == b.t && a.shape->id == b.shape->id);
}
