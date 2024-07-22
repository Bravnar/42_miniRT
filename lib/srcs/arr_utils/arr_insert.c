/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:51:07 by hmorand           #+#    #+#             */
/*   Updated: 2024/06/25 15:51:11 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	**arr_insert(char **arr, int pos, char *elem)
{
	int		i;
	int		j;
	int		len;
	char	**new_arr;

	if (!arr)
		len = 0;
	else
		len = strarr_len(arr);
	new_arr = malloc(sizeof(char *) * (len + 2));
	if (!new_arr)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < len + 1)
	{
		if (i != pos)
			new_arr[i] = ft_strdup(arr[j++]);
		else
			new_arr[i] = ft_strdup(elem);
	}
	ft_free_arr(arr);
	new_arr[i] = NULL;
	return (new_arr);
}
