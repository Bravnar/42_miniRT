/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:17:28 by bravnar           #+#    #+#             */
/*   Updated: 2023/11/07 09:59:00 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/* #include <string.h>
#include <stdio.h>

int main() 
{
    char str[] = "Hello, world!";
    int search_char = 'o';
    size_t n = ft_strlen(str);
	
    void *ft_result = ft_memchr(str, search_char, n);
    if (ft_result != NULL) 
	{
        printf("ft_memchr: Found '%c' at position %ld\n", 
			search_char, (char *)ft_result - str);
    } 
	else 
	{
        printf("ft_memchr: '%c' not found\n", search_char);
    }

    void *mem_result = memchr(str, search_char, n);
    if (mem_result != NULL) {
        printf("memchr: Found '%c' at position %ld\n", 
			search_char, (char *)mem_result - str);
    } else {
        printf("memchr: '%c' not found\n", search_char);
    }

    return 0;
} */
