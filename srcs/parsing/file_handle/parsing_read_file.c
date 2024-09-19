/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:48:19 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/19 16:55:56 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_full_id(char *id)
{
	if (!ft_strcmp(id, "R"))
		return (1);
	else if (!ft_strcmp(id, "C"))
		return (1);
	else if (!ft_strcmp(id, "A"))
		return (1);
	else if (!ft_strcmp(id, "L"))
		return (1);
	else if (!ft_strcmp(id, "cy"))
		return (1);
	else if (!ft_strcmp(id, "sp"))
		return (1);
	else if (!ft_strcmp(id, "pl"))
		return (1);
	return (0);
	
}

void	check_identifier(char *identifier, t_parse *node,
	char **tmp, t_file *file)
{
	char	*copy;

	if (ft_strisalpha(identifier))
	{
		if (!check_full_id(identifier))
		{
			copy = ft_strdup(identifier);
			free_nodes(node);
			ft_free_arr(tmp);
			err_template(M_UKNOWN_ID, copy, file);
		}
	}
	else
	{
		copy = ft_strdup(identifier);
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
