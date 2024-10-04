/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:24:11 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/20 10:24:31 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_ids(char *identifier)
{
	if (!ft_strcmp(identifier, "R"))
		return ;
	else if (!ft_strcmp(identifier, "C"))
		return ;
	else if (!ft_strcmp(identifier, "A"))
		return ;
	else if (!ft_strcmp(identifier, "L"))
		return ;
	else if (!ft_strcmp(identifier, "cy"))
		return ;
	else if (!ft_strcmp(identifier, "pl"))
		return ;
	else if (!ft_strcmp(identifier, "sp"))
		return ;
	add_error(identifier, M_UKNOWN_ID);
}

void	read_rt(char *filename, t_file *file)
{
	t_parse	*node;
	char	*line;

	file->fd = open(filename, O_RDONLY);
	if (file->fd == -1)
		add_error(filename, M_OPEN_FAILED);
	line = ft_strdup("");
	while (line)
	{
		free(line);
		line = get_next_line(file->fd);
		if (!ft_strcmp(line, "\n"))
			continue ;
		node = new_parse_node(line);
		add_node(&file->parse, node);
	}
	free(line);
}
