/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:23:58 by smuravyev         #+#    #+#             */
/*   Updated: 2023/11/07 10:16:33 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*s3;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	s3 = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i++] = s2[j];
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

/* #include <stdio.h>

int	main(void)
{
	char *s1 = "my favorite animal is";
 	char *s2 = " ";
 	char *s3 = "the nyancat";
 	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);
	printf("The new string is: %s\n", res);
} */