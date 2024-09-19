/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:46:18 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 12:56:32 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_identifier(char *identifier)
{
	if (ft_strisalpha(identifier))
	{
		if (!ft_strstr(GOOD_ID, identifier))
		{
			printf(BOLD_WHITE"\t---> %s\n"RESET, identifier);
			err_template(M_UKNOWN_ID, identifier, NULL);
		}
	}
	else
	{
		printf(BOLD_WHITE"\t---> %s\n"RESET, identifier);
		err_template(M_UKNOWN_ID, identifier, NULL);
	}
}

void	read_rt(char *filename, t_file *file)
{
	t_parse	*node;
	char	*line;

	file->fd = open(filename, O_RDONLY);
	if (file->fd == -1)
		err_template(M_OPEN_FAILED, filename, file);
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
