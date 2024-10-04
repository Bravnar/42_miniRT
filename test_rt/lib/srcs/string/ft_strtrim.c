/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:43:25 by smuravyev         #+#    #+#             */
/*   Updated: 2024/05/28 11:09:36 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (j > 0)
	{
		while (s1[j - 1] && ft_strrchr(set, s1[j - 1]) && j > i)
			j--;
	}
	substr = ft_substr(s1, i, j - i);
	return (substr);
}

/* #include <stdio.h>

int	main(void)
{
	char	*str = "    pp01234567890pp    ";
	char	*set = " ";
	char	*trimmed_str = ft_strtrim(str, set);
	printf("The trimmed string is: %s\n", trimmed_str);
}
 */