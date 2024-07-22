/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:34:48 by smuravyev         #+#    #+#             */
/*   Updated: 2024/01/30 17:54:24 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strndup(const char *s, size_t n)
{
	char		*new_str;
	size_t		i;

	i = 0;
	new_str = malloc(sizeof(char) * (n + 1));
	if (!new_str)
		return (NULL);
	while (s[i] && i < n)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
