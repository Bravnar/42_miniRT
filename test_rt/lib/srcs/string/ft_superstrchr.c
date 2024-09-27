/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superstrchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:00:06 by hmorand           #+#    #+#             */
/*   Updated: 2024/06/25 15:00:06 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_superstrchr(char *s, char *chars)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(chars, s[i]))
			return ((char *)(s + i));
		i++;
	}
	if (ft_strchr(chars, s[i]))
		return ((char *)s + i);
	return (NULL);
}
