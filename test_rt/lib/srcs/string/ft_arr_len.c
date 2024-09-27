/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:24:54 by smuravye          #+#    #+#             */
/*   Updated: 2024/07/29 16:25:24 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	ft_arr_len(char **split)
{
	int	i;

	i = 0;
	if (!split && !split[0])
		return (i);
	while (split[i])
		i++;
	return (i);
}
