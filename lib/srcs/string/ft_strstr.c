/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:09:32 by smuravye          #+#    #+#             */
/*   Updated: 2024/07/31 10:15:18 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j])
		{
			if(!little[j + 1])
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
