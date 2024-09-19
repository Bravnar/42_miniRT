/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:43:04 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/19 15:43:17 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_identifier(char *identifier, t_parse *node, char **tmp, t_file *file)
{
	char	*copy;

	if (ft_strisalpha(identifier))
	{
		if (!ft_strstr(GOOD_ID, identifier))
		{
			copy =ft_strdup(identifier);
			printf(BOLD_WHITE"\t---> %s\n"RESET, identifier);
			free_nodes(node);
			ft_free_arr(tmp);
			err_template(M_UKNOWN_ID, copy, file);
		}
	}
	else
	{
		copy = ft_strdup(identifier);
		printf(BOLD_WHITE"\t---> %s\n"RESET, identifier);
		free_nodes(node);
		ft_free_arr(tmp);
		err_template(M_UKNOWN_ID, copy, file);
	}
}

void	read_rt(char *filename, t_file *file)
{
	t_parse	*node;
	int		i;
	char	*line;

	file->fd = open(filename, O_RDONLY);
	if (file->fd == -1)
		err_template(M_OPEN_FAILED, filename, file);
	i = 0;
	while (i == 0 || line)
	{
		line = get_next_line(file->fd);
		if (!ft_strcmp(line, "\n"))
		{
			free_str(line);
			continue ;
		}
		node = new_parse_node(line, file);
		add_node(&file->parse, node);
		i++;
	}
	free_str(line);
}
