/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20/09/2024 09:56:46 by hmorand           #+#    #+#             */
/*   Updated: 20/09/2024 10:07:58 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_errors	**get_errors(void)
{
	static t_errors	*errors = NULL;

	return (&errors);
}

void	add_error(char *location, char *message)
{
	t_errors	*new_error;
	t_errors	*curr;

	new_error = malloc(sizeof(t_errors));
	if (!new_error)
		return ;
	new_error->location = ft_strdup(location);
	new_error->err_msg = ft_strdup(message);
	new_error->next = NULL;
	curr = *get_errors();
	if (!curr)
	{
		*get_errors() = new_error;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new_error;
}

void	free_errors(void)
{
	t_errors	*curr;
	t_errors	*tmp;

	tmp = NULL;
	curr = *get_errors();
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		if (tmp->location)
			free(tmp->location);
		if (tmp->err_msg)
			free(tmp->err_msg);
		free(tmp);
	}
	*get_errors() = NULL;
}

void	print_errors(void)
{
	t_errors	*tmp;

	tmp = *get_errors();
	while (tmp)
	{
		err_template(tmp->err_msg, tmp->location);
		tmp = tmp->next;
	}
}
