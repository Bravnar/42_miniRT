/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:50:31 by bravnar           #+#    #+#             */
/*   Updated: 2023/11/07 10:16:48 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(little[0]))
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (!little[j + 1])
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	(void) ac;
	char *string_1 = av[1];
	char *string_2 = av[2];
	size_t	length = atoi(av[3]);

	printf("Testing......... \n\n");
	printf("Your big string: \"%s\"\n", string_1);
	printf("Your little string: \"%s\"\n", string_2);
	printf("Searching until length = %ld\n\n", length);
	printf("Result with FT_STRNSTR: %s\n\n", 
		ft_strnstr(string_1, string_2, length));
	//printf("Result with STRNSTR: %s\n\n", strnstr(string_1, string_2, length));
} */
