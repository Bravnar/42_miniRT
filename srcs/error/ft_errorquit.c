/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorquit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:52:25 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/19 11:52:33 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* NEW */
char	*simple_replace(char *str, char what, char with)
{
	char	*copy;
	int		i;

	i = 0;
	copy = ft_strdup(str);
	while (copy[i])
	{
		if (copy[i] == what)
			copy[i] = with;
		i++;
	}
	return (copy);
}

/* NEW */

void	err_template(char *msg, char *line)
{
	char	*e_line;
	char	*e_line_trim;

	e_line = NULL;
	if (line)
	{
		e_line = simple_replace(line, '\t', ' ');
		e_line_trim = ft_strtrim(e_line, "\n");
		free(e_line);
	}
	ft_fprintf(2, BOLD_RED"%s\nParseError\n\n"RESET, ERRLINE);
	if (e_line_trim)
	{
		if (ft_strlen(e_line_trim) > 12)
			ft_fprintf(2, BOLD_WHITE"In line:\t"RESET);
		else
			ft_fprintf(2, BOLD_WHITE"Error Location:\t"RESET);
		ft_fprintf(2, "%s\n", e_line_trim);
		free(e_line_trim);
	}
	ft_fprintf(2, BOLD_ORANGE"\n%s\n"RESET, msg);
	ft_fprintf(2, BOLD_RED"%s\n"RESET, ERRLINE);
	free_map(get_map());
	exit(1);
}

/* OLD */
void	err_quit(char *msg)
{
	ft_fprintf(2, BOLD_RED"Error:\t"RESET);
	ft_fprintf(2, BOLD_YELLOW"%s\n"RESET, msg);
	exit(1);
}
