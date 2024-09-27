/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:37:35 by hmorand           #+#    #+#             */
/*   Updated: 2024/06/25 16:37:35 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	if (!arr[i])
	{
		free(arr);
		arr = NULL;
		return ;
	}
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}
