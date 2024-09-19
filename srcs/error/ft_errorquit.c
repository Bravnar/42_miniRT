/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorquit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:38:10 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 10:38:12 by smuravye         ###   ########.fr       */
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
<<<<<<< HEAD
	char	*e_line_trim;
=======
>>>>>>> 738653dab346508aa39caeb447b0eb7a796cd412

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
