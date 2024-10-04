/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:20:37 by hmorand           #+#    #+#             */
/*   Updated: 2024/06/24 14:20:37 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	free_strs(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

int	check_exists(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	return (1);
}

char	*ft_better_join(char *s1, char *s2, int free_)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!check_exists(s1, s2))
		return (NULL);
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		result[j++] = s2[i];
		i++;
	}
	if (free_ == 1)
		free_strs(s1, s2);
	return (result);
}
