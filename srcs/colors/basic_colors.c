/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 30/08/2024 13:47:24 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:36:56 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_color	black(void)
{
	return (color(0, 0, 0));
}

t_color	white(void)
{
	return (color(255, 255, 255));
}

t_color	c(char *name)
{
	if (ft_strcmp(name, "red") == 0)
		return (color(255, 0, 0));
	else if (ft_strcmp(name, "green") == 0)
		return (color(0, 128, 0));
	else if (ft_strcmp(name, "blue") == 0)
		return (color(30, 144, 255));
	else if (ft_strcmp(name, "yellow") == 0)
		return (color(255, 255, 0));
	else if (ft_strcmp(name, "cyan") == 0)
		return (color(0, 255, 255));
	else if (ft_strcmp(name, "magenta") == 0)
		return (color(255, 0, 255));
	else if (ft_strcmp(name, "gray") == 0)
		return (color(128, 128, 128));
	else if (ft_strcmp(name, "orange") == 0)
		return (color(255, 140, 0));
	else if (ft_strcmp(name, "purple") == 0)
		return (color(138, 43, 226));
	else if (ft_strcmp(name, "pink") == 0)
		return (color(255, 192, 203));
	else
		return (color(128, 128, 128));
}
