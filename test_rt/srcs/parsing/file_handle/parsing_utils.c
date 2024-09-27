/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:25:29 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/20 10:25:29 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_type(t_type *type, char *identifier)
{
	check_ids(identifier);
	if (!ft_strcmp(identifier, "R"))
		*type = WINDOW;
	else if (!ft_strcmp(identifier, "A"))
		*type = AMBIENT;
	else if (!ft_strcmp(identifier, "C"))
		*type = CAMERA;
	else if (!ft_strcmp(identifier, "L"))
		*type = LIGHTS;
	else if (ft_strstr(GOOD_ID, identifier))
		*type = OBJECTS;
}

char	**set_type_and_clean(char **tmp, t_type *type)
{
	char	**ret;
	int		len;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len = ft_arr_len(tmp);
	set_type(type, tmp[0]);
	ret = malloc(sizeof(char *) * len);
	if (!ret)
		return (NULL);
	while (tmp[i])
	{
		ret[j] = ft_strdup(tmp[i++]);
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

void	check_arr_extr(char **arr)
{
	int	i;
	int	len;

	i = 0;
	while (arr[i])
	{
		len = ft_strlen(arr[i]) - 1;
		if ((!ft_isalnum(arr[i][0]) && arr[i][0] != '-') \
			|| !ft_isalnum(arr[i][len]))
			add_error(arr[i], M_INVALID_SEP);
		i++;
	}
}
