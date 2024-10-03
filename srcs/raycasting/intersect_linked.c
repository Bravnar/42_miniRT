/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_linked.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:15:48 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 16:19:11 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Creates a new intersection node.
 *
 * This function allocates and initializes a new node for storing intersection
 * data. The node is created using the provided intersection data.
 *
 * @param i The intersection data to be stored in the new node.
 * @return A pointer to the newly created intersection node.
 */
t_inter	*new_inter_node(t_intersection i)
{
	t_inter	*node;

	node = ft_calloc(1, sizeof(t_inter));
	if (!node)
		return (NULL);
	node->i = i;
	node->next = NULL;
	return (node);
}

/**
 * @brief Adds new intersection nodes to the
 * head of the intersection linked list.
 *
 * This function takes a pointer to the head of the intersection linked list and
 * a pointer to the new intersection nodes to be added. It inserts the new nodes
 * at the beginning of the list, updating the head pointer accordingly.
 *
 * @param head A double pointer to the head of the intersection linked list.
 * @param new_nodes A double pointer to the new intersection nodes to be added.
 */
void	add_inter_nodes(t_inter **head, t_inter **new_nodes)
{
	t_inter	*tmp;

	if (new_nodes == NULL)
		return ;
	tmp = *new_nodes;
	while (tmp)
	{
		add_inter_node(head, new_inter_node(tmp->i));
		tmp = tmp->next;
	}
}

/**
 * @brief Adds a new intersection node to the linked list.
 *
 * This function takes a pointer to the head of a linked list of
 * intersection nodes and a new intersection node, and adds
 * the new node to the list and inserts it in a sorted way.
 *
 * @param head A double pointer to the head of
 * the sorted linked list of intersection nodes.
 * @param new_node A pointer to the new
 * intersection node to be added to the list.
 */
void	add_inter_node(t_inter **head, t_inter *new_node)
{
	t_inter	*tmp;

	if (!*head)
		*head = new_node;
	else
	{
		tmp = *head;
		if (new_node->i.t <= tmp->i.t)
		{
			new_node->next = tmp;
			*head = new_node;
		}
		else
		{
			while (tmp->next && tmp->next->i.t < new_node->i.t)
				tmp = tmp->next;
			new_node->next = tmp->next;
			tmp->next = new_node;
		}
	}
}

/**
 * @brief Contains the function to remove an intersection node
 * from a linked list.
 *
 * @param head A double pointer to the head of the linked list.
 * @param to_remove A pointer to the node that needs to be removed from the list.
 */
void	remove_inter(t_inter **head, t_inter *to_remove)
{
	t_inter	*tmp;

	tmp = *head;
	if (tmp == to_remove)
	{
		*head = (*head)->next;
		free(tmp);
	}
	else
	{
		while (tmp->next && tmp->next != to_remove)
		{
			tmp = tmp->next;
		}
		if (tmp->next == to_remove)
		{
			tmp->next = to_remove->next;
			free(to_remove);
		}
	}
}
