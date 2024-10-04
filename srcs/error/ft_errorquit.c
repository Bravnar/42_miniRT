/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorquit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:58:43 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 15:58:59 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Replaces all occurrences of a specified
 * character in a string with another character.
 *
 * This function iterates through the given string and replaces each occurrence
 * of the character 'what' with the character 'with'.
 *
 * @param str The string in which the replacement will occur.
 * @param what The character to be replaced.
 * @param with The character to replace with.
 * @return The modified string with the replacements made.
 */
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

/**
 * @brief Template function to handle errors.
 *
 * This function is used to handle errors by displaying a
 * message and the line where the error occurred.
 *
 * @param msg The error message to be displayed.
 * @param line The line where the error occurred.
 */
void	err_template(char *msg, char *line)
{
	char	*e_line;
	char	*e_line_trim;

	e_line = NULL;
	e_line_trim = NULL;
	if (line)
	{
		e_line = simple_replace(line, '\t', ' ');
		e_line_trim = ft_strtrim(e_line, "\n");
		free(e_line);
	}
	ft_fprintf(2, BOLD_RED"%s\n"RESET, ERRLINE);
	ft_fprintf(2, BOLD_RED"ParseError\n\n"RESET);
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
}

/**
 * @brief Contains the error handling function for
 * quitting the program with a message.
 *
 * This file provides the implementation of the err_quit function,
 * which is used to display an error message and terminate the program.
 *
 * @param msg The error message to be displayed before quitting.
 */
void	err_quit(char *msg)
{
	ft_fprintf(2, BOLD_RED"Error:\t"RESET);
	ft_fprintf(2, BOLD_YELLOW"%s\n"RESET, msg);
	exit(1);
}
