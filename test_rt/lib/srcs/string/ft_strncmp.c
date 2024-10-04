/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:02:00 by hmorand           #+#    #+#             */
/*   Updated: 2024/06/24 11:02:00 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	if (!s2 && !s1)
		return (0);
	if (!s1)
		return (s2[0]);
	if (!s2)
		return (s1[0]);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] || s2[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* #include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	(void)	ac;
	char 	*str1 = av[1];
	char 	*str2 = av[2];
	size_t	n = atoi(av[3]);

	printf("Output with ft_strncmp: %d\n\n", ft_strncmp(str1, str2, n));
	printf("Output with the original strncmp: %d\n\n", strncmp(str1, str2, n));
	return (0);
} */
