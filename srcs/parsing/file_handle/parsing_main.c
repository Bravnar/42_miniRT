/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:46:03 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/20 08:48:54 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_file_name(char *name)
{
	size_t	length;
	char	*tested_string;

	length = ft_strlen(name);
	tested_string = ft_strstr(name + length - 3, ".rt");
	if (ft_strlen(tested_string) > 3)
		return (0);
	if (!tested_string)
		return (0);
	return (1);
}

t_file	parse_file(char *filename)
{
	t_file	file;

	file.fd = -1;
	file.parse = NULL;
	if (!check_file_name(filename))
		add_error(filename, M_WRONG_EXT);
	ft_bzero(&file.count, sizeof(t_count));
	read_rt(filename, &file);
	if (!RT_BONUS)
	{
		check_count(&file);
		check_params(&file);
	}
	else
	{
		check_count_bonus(&file);
		check_params_bonus(&file);
	}
	return (file);
}
