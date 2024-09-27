/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:27:15 by bravnar           #+#    #+#             */
/*   Updated: 2023/11/07 09:59:03 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
    // Test case 1: Strings are equal
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    size_t len = strlen(str1);

    int result_ft = ft_memcmp(str1, str2, len);
    int result_std = memcmp(str1, str2, len);

    printf("Test Case 1:\n");
    printf("ft_memcmp result: %d\n", result_ft);
    printf("memcmp result: %d\n", result_std);

    // Test case 2: Strings are different
    char str3[] = "Hello, OpenAI!";
    char str4[] = "Hello, World!";

    result_ft = ft_memcmp(str3, str4, len);
    result_std = memcmp(str3, str4, len);

    printf("\nTest Case 2:\n");
    printf("ft_memcmp result: %d\n", result_ft);
    printf("memcmp result: %d\n", result_std);

    return 0;
} */