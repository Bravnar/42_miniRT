/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:45:51 by codespace         #+#    #+#             */
/*   Updated: 2023/11/07 10:16:50 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			j = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		j = (char *)(s + i);
	return (j);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
	char string[5] = "hello";
	printf("Using ft_strrchr: %s\n", ft_strrchr(string, 'l'));
	printf("Using original strrchr: %s\n", strrchr(string, 'l'));
}
 */