/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:36:15 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/07 10:16:43 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	char	*result;
	size_t	i;

	length = ft_strlen(s);
	result = malloc(sizeof(*s) * (length + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* #include <stdio.h>

static char adjusted_to_upper(unsigned int index, char c)
{
	(void) index;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

int	main(void)
{
	char const *s = "Hello World!";
	char *result = ft_strmapi(s, adjusted_to_upper);
	if (result)
	{
		printf("Original: %s\n", s);
		printf("Mapped: %s\n", result);
		free(result);
	}
	return (0);
}
 */