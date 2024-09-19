/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:51:55 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/19 15:51:55 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_parse	*new_parse_node(char *line, t_file *file)
{
	t_parse	*node;
	char	**tmp;

	node = ft_calloc(1, sizeof(t_parse));
	if (!node)
		return (NULL);
	node->line = ft_strdup(line);
	free_str(line);
	if (line)
	{
		tmp = ft_megasplit(node->line, WHITESPACE);
		node->next = NULL;
		node->line_split = set_type_and_clean(tmp, node, file);
		node->id = ft_strdup(tmp[0]);
		node->count = ft_arr_len(node->line_split);
		check_arr_extr(node->line_split, file, tmp, node);
		ft_free_arr(tmp);
	}
	node->next = NULL;
	return (node);
}

void	add_node(t_parse **parsed, t_parse *new_node)
{
	t_parse	*tmp;

	if (!*parsed)
		*parsed = new_node;
	else
	{
		tmp = *parsed;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void	free_nodes(t_parse *list)
{
	t_parse	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp->line)
			free(tmp->line);
		if (tmp->line_split)
			ft_free_arr(tmp->line_split);
		if (tmp->id)
			free(tmp->id);
		free(tmp);
	}
	tmp = NULL;
}
